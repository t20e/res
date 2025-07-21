import torch
import sys
import unittest

# sys.path.append("ML/Pytorch/object_detection/metrics/")
# from mean_avg_precision import mean_average_precision
from IOU import intersection_over_union

from collections import Counter

def mean_average_precision(
    pred_bboxes,
    true_bboxes,
    iou_threshold=0.5,
    box_format="corners",
    num_classes = 20
):
    """
    Compute Mean Average Precision (mAP), this function isn't the most effiecent implementation of mAP
    
    NOTE: this implementation is only for a single IOU = 0.5, if we want to compute this for multiple IOU's = [0.5, 0.55, 0.9, etcc..] then call this function for for each IOU, store the result in a list and then take the average from that list
    
    Parameters
    -----------
        pred_bboxes (list): all predicted output from the models for all images in the test set. [ [train_idx, class_pred, prob_score, x1, y1, x2, y2], [etc..], etc..], train_idx = what image is it.
        true_bboxes (list): all true bounding boxes from the images in the test set. Almost identical to the structure of pred_bboxes.
        iou_threshold (float): the threshold to remove predicted bounding boxes if it doesnt cover the true bounding boxes enough
        box_format (string): from where to draw the predicted bounding boxes, from corners or mid-point
        num_classes (int): how many classes are we predicting [example: dogs, cats, cars, etc..]
    
    
    Return
    ------
        mAP
    """
    # list storing all AP for respective classes
    average_precision = []
    epsilon = 1e-6# for numerical stability
    
    # we need to calculate for each class
    for c in range(num_classes):
        detections = [] 
        ground_truths = []
        
        
        # Go through all predictions
        for detect in pred_bboxes:
            if detect[1] == c: #[1] is the class_pred, if its the same as the class were currently looking at then append
                detections.append(detect) 
        #Go through all targets
        for t_b in true_bboxes:
            if t_b[1] == c: 
                ground_truths.append(t_b)
        
        # [0] is the image index in the dataset
        # ex: image 0 has 3 bounding boxes
        # ex: image 1 has 5 bounding boxes
        # amount_bboxes = { 0 : 3, 1 : 5}
        amount_bboxes = Counter([gt[0] for gt in ground_truths])
        
        # this is to keep track of the bounding boxes that we have seen
        for key, val in amount_bboxes.items():
            # turns the 3 here counter = { 0 : 3, 1 : 5} into a tensor of 3 elements of zero's
            # amount_bboxes = { 0 : torch.tensor([0,0,0]), 1 : torch.tensor([0,0,0,0,0])}
            amount_bboxes[key] = torch.zeros(val)
            
        
        detections.sort(key=lambda x: x[2], reverse=True) # sort over the prob_scores, this is the 2.1 in the markdown
        TP = torch.zeros((len(detections)))# True positives
        FP = torch.zeros((len(detections)))# False positives
        total_true_bboxes = len(ground_truths)
        
        # If none exists for this class then we can safely skip
        if total_true_bboxes == 0:
            continue
        
        for detect_idx, detect in enumerate(detections):
            ground_truth_img = [
                bbox for bbox in ground_truths if bbox[0] == detect[0] # we are only taking the ground truths that have the same index as out detected/ predicted
            ]
            
            num_gts = len(ground_truth_img) # number of ground truths
            best_iou = 0
            
            # go through all the ground truth bounding box for this image
            for idx, gt in enumerate(ground_truth_img):
                iou = intersection_over_union(
                    torch.tensor(detect[3:]), # only sending the coordinates of the bbox [x1, y1, x2, y2]
                    torch.tensor(gt[3:]), # only sending the coordinates of the bbox [x1, y1, x2, y2]
                    box_format=box_format,
                )
                
                if iou > best_iou:
                    best_iou = iou
                    best_gt_idx = idx
            
            if best_iou > iou_threshold: # means that this prediction was correct 
                # if it eqauls to 0 than we haven't looked at that bbox yet
                if amount_bboxes[detect[0]][best_gt_idx] == 0: # but we also need to check that this bbox hasn't been looked at already
                    TP[detect_idx] = 1
                    amount_bboxes[detect[0]][best_gt_idx] = 1 # since we've covered this bbox, we set this to 1
                else:
                    FP[detect_idx] = 1
            else: # if IOU is lower then the detection is a false positive
                FP[detect_idx] = 1
        
        ### Precision and Recall 
        # [1, 1, 0, 1] --> [1, 2, 2, 3, 3] # the first list the 1 means correctly predicted and the 0 means incorrectly predicted
        TP_cumsum = torch.cumsum(TP, dim=0)
        
        FP_cumsum = torch.cumsum(FP, dim=0)
        
        recalls = TP_cumsum / (total_true_bboxes + epsilon)
        
        precision = torch.divide(TP_cumsum, (TP_cumsum + FP_cumsum + epsilon))
        
        precision = torch.cat((torch.tensor([1]), precision)) # we need to add a 1, because we want to start at the point zero one torch.tensor([1]) because precision is the y-axis on the graph
        recalls = torch.cat((torch.tensor([0]), recalls)) # we need to add a 1, because we want to start at the point zero one torch.tensor([0]) because recalls is the x-axis on the graph
        
        average_precision.append(torch.trapz(precision, recalls))  # this is 5.1 calculate the area under PR curve
        
    return sum(average_precision) / len(average_precision)


class TestMeanAveragePrecision(unittest.TestCase):
    def setUp(self):
        # test cases we want to run
        self.t1_preds = [
            [0, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t1_targets = [
            [0, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t1_correct_mAP = 1

        self.t2_preds = [
            [1, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t2_targets = [
            [1, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t2_correct_mAP = 1

        self.t3_preds = [
            [0, 1, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 1, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 1, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t3_targets = [
            [0, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t3_correct_mAP = 0

        self.t4_preds = [
            [0, 0, 0.9, 0.15, 0.25, 0.1, 0.1],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]

        self.t4_targets = [
            [0, 0, 0.9, 0.55, 0.2, 0.3, 0.2],
            [0, 0, 0.8, 0.35, 0.6, 0.3, 0.2],
            [0, 0, 0.7, 0.8, 0.7, 0.2, 0.2],
        ]
        self.t4_correct_mAP = 5 / 18

        self.epsilon = 1e-4

    def test_all_correct_one_class(self):
        mean_avg_prec = mean_average_precision(
            self.t1_preds,
            self.t1_targets,
            iou_threshold=0.5,
            box_format="midpoint",
            num_classes=1,
        )
        self.assertTrue(abs(self.t1_correct_mAP - mean_avg_prec) < self.epsilon)

    def test_all_correct_batch(self):
        mean_avg_prec = mean_average_precision(
            self.t2_preds,
            self.t2_targets,
            iou_threshold=0.5,
            box_format="midpoint",
            num_classes=1,
        )
        self.assertTrue(abs(self.t2_correct_mAP - mean_avg_prec) < self.epsilon)

    def test_all_wrong_class(self):
        mean_avg_prec = mean_average_precision(
            self.t3_preds,
            self.t3_targets,
            iou_threshold=0.5,
            box_format="midpoint",
            num_classes=2,
        )
        self.assertTrue(abs(self.t3_correct_mAP - mean_avg_prec) < self.epsilon)

    def test_one_inaccurate_box(self):
        mean_avg_prec = mean_average_precision(
            self.t4_preds,
            self.t4_targets,
            iou_threshold=0.5,
            box_format="midpoint",
            num_classes=1,
        )
        self.assertTrue(abs(self.t4_correct_mAP - mean_avg_prec) < self.epsilon)

    def test_all_wrong_class(self):
        mean_avg_prec = mean_average_precision(
            self.t3_preds,
            self.t3_targets,
            iou_threshold=0.5,
            box_format="midpoint",
            num_classes=2,
        )
        self.assertTrue(abs(self.t3_correct_mAP - mean_avg_prec) < self.epsilon)


        
if __name__ == "__main__":
    print("Running Mean Average Precisions Tests:")
    unittest.main()
    
    