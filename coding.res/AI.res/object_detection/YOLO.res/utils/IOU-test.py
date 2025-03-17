import torch


import sys
import unittest

# sys.path.append("ML/Pytorch/object_detection/metrics/")


def intersection_over_union(boxes_preds, boxes_labels, box_format="midpoint"):
    """
    Parameters:
        boxes_pred (python:list): the predicted bounding boxes, shape of (batch_size/N, 4) 4 represents x1, y1, x2, y2
        boxes_labels (python:list): the true labels bounding boxes, shape of (batch_size, 4) 4 represents x1, y1, x2, y2
        
        box_format: (str = "midpoint" or "corners") : how to calculate the bboxes
        
        NOTE: 
            Some bboxes datasets are draw from the midpoint then the height and weight of the bounding box, others are draw from the x1, y1, x2, y2 coordinates
        
    Returns: IOU between two bboxes
    """
    # grab the coordinates
    if box_format== "midpoint":
        # boxes_preds[..., 0:1] is the midpoint
        # boxes_preds[..., 2:3] is the width of that bbox
        # so if we divide it by 2, then well get the top-left x1 coordinate
        box1_x1 = boxes_preds[..., 0:1] - boxes_preds[..., 2:3] / 2
        box1_y1 = boxes_preds[..., 1:2] - boxes_preds[..., 3:4] / 2
        box1_x2 = boxes_preds[..., 0:1] + boxes_preds[..., 2:3] / 2
        box1_y2 = boxes_preds[..., 1:2] + boxes_preds[..., 3:4] / 2
        
        box2_x1 = boxes_labels[..., 0:1] - boxes_labels[..., 2:3] / 2
        box2_y1 = boxes_labels[..., 1:2] - boxes_labels[..., 3:4] / 2
        box2_x2 = boxes_labels[..., 0:1] + boxes_labels[..., 2:3] / 2
        box2_y2 = boxes_labels[..., 1:2] + boxes_labels[..., 3:4] / 2
        
    if box_format == "corners":
        box1_x1 = boxes_preds[..., 0:1] # the ... keeps all the previous dimensions, 
        box1_y1 = boxes_preds[..., 1:2]
        box1_x2 = boxes_preds[..., 2:3]
        box1_y2 = boxes_preds[..., 3:4] # slice the tensor. but keep its shape, 
        
        box2_x1 = boxes_labels[..., 0:1] # the ... keeps all the previous dimensions, 
        box2_y1 = boxes_labels[..., 1:2]
        box2_x2 = boxes_labels[..., 2:3]
        box2_y2 = boxes_labels[..., 3:4]
    
    
    # compute the yellow intersecion box from the images, its the intersection box where the two bboxes share area
    x1 = torch.max(box1_x1, box2_x1)
    y1 = torch.max(box1_y1, box2_y1)
    x2 = torch.min(box1_x2, box2_x2)
    y2 = torch.min(box1_y2, box2_y2)
    
    # the .clamp(0) is only for cases when the bounding boxes dont intersect
    intersection = (x2 - x1).clamp(0) * (y2 - y1).clamp(0)
    
    
    # calculate the UNION which is the pink drawn box, or just the total area of both the bboxes together
    # the abs() is to make sure we dont have negatives
    box1_area = abs((box1_x2 - box1_x1) * (box1_y2 - box1_y1))
    box2_area = abs((box2_x2 - box2_x1) * (box2_y2 - box2_y1))
    
    # Calculate and return the intersection over union, the 1e-6 is for numerical stability
    return intersection / (box1_area + box2_area - intersection + 1e-6)






class TestIntersectionOverUnion(unittest.TestCase):
    def setUp(self):
        # test cases we want to run
        self.t1_box1 = torch.tensor([0.8, 0.1, 0.2, 0.2])
        self.t1_box2 = torch.tensor([0.9, 0.2, 0.2, 0.2])
        self.t1_correct_iou = 1 / 7

        self.t2_box1 = torch.tensor([0.95, 0.6, 0.5, 0.2])
        self.t2_box2 = torch.tensor([0.95, 0.7, 0.3, 0.2])
        self.t2_correct_iou = 3 / 13

        self.t3_box1 = torch.tensor([0.25, 0.15, 0.3, 0.1])
        self.t3_box2 = torch.tensor([0.25, 0.35, 0.3, 0.1])
        self.t3_correct_iou = 0

        self.t4_box1 = torch.tensor([0.7, 0.95, 0.6, 0.1])
        self.t4_box2 = torch.tensor([0.5, 1.15, 0.4, 0.7])
        self.t4_correct_iou = 3 / 31

        self.t5_box1 = torch.tensor([0.5, 0.5, 0.2, 0.2])
        self.t5_box2 = torch.tensor([0.5, 0.5, 0.2, 0.2])
        self.t5_correct_iou = 1

        # (x1,y1,x2,y2) format
        self.t6_box1 = torch.tensor([2, 2, 6, 6])
        self.t6_box2 = torch.tensor([4, 4, 7, 8])
        self.t6_correct_iou = 4 / 24

        self.t7_box1 = torch.tensor([0, 0, 2, 2])
        self.t7_box2 = torch.tensor([3, 0, 5, 2])
        self.t7_correct_iou = 0

        self.t8_box1 = torch.tensor([0, 0, 2, 2])
        self.t8_box2 = torch.tensor([0, 3, 2, 5])
        self.t8_correct_iou = 0

        self.t9_box1 = torch.tensor([0, 0, 2, 2])
        self.t9_box2 = torch.tensor([2, 0, 5, 2])
        self.t9_correct_iou = 0

        self.t10_box1 = torch.tensor([0, 0, 2, 2])
        self.t10_box2 = torch.tensor([1, 1, 3, 3])
        self.t10_correct_iou = 1 / 7

        self.t11_box1 = torch.tensor([0, 0, 3, 2])
        self.t11_box2 = torch.tensor([1, 1, 3, 3])
        self.t11_correct_iou = 0.25

        self.t12_bboxes1 = torch.tensor(
            [
                [0, 0, 2, 2],
                [0, 0, 2, 2],
                [0, 0, 2, 2],
                [0, 0, 2, 2],
                [0, 0, 2, 2],
                [0, 0, 3, 2],
            ]
        )
        self.t12_bboxes2 = torch.tensor(
            [
                [3, 0, 5, 2],
                [3, 0, 5, 2],
                [0, 3, 2, 5],
                [2, 0, 5, 2],
                [1, 1, 3, 3],
                [1, 1, 3, 3],
            ]
        )
        self.t12_correct_ious = torch.tensor([0, 0, 0, 0, 1 / 7, 0.25])

        # Accept if the difference in iou is small
        self.epsilon = 0.001

    def test_both_inside_cell_shares_area(self):
        iou = intersection_over_union(self.t1_box1, self.t1_box2, box_format="midpoint")
        self.assertTrue((torch.abs(iou - self.t1_correct_iou) < self.epsilon))

    def test_partially_outside_cell_shares_area(self):
        iou = intersection_over_union(self.t2_box1, self.t2_box2, box_format="midpoint")
        self.assertTrue((torch.abs(iou - self.t2_correct_iou) < self.epsilon))

    def test_both_inside_cell_shares_no_area(self):
        iou = intersection_over_union(self.t3_box1, self.t3_box2, box_format="midpoint")
        self.assertTrue((torch.abs(iou - self.t3_correct_iou) < self.epsilon))

    def test_midpoint_outside_cell_shares_area(self):
        iou = intersection_over_union(self.t4_box1, self.t4_box2, box_format="midpoint")
        self.assertTrue((torch.abs(iou - self.t4_correct_iou) < self.epsilon))

    def test_both_inside_cell_shares_entire_area(self):
        iou = intersection_over_union(self.t5_box1, self.t5_box2, box_format="midpoint")
        self.assertTrue((torch.abs(iou - self.t5_correct_iou) < self.epsilon))

    def test_box_format_x1_y1_x2_y2(self):
        iou = intersection_over_union(self.t6_box1, self.t6_box2, box_format="corners")
        self.assertTrue((torch.abs(iou - self.t6_correct_iou) < self.epsilon))

    def test_additional_and_batch(self):
        ious = intersection_over_union(
            self.t12_bboxes1, self.t12_bboxes2, box_format="corners"
        )
        all_true = torch.all(
            torch.abs(self.t12_correct_ious - ious.squeeze(1)) < self.epsilon
        )
        self.assertTrue(all_true)


if __name__ == "__main__":
    print("Running Intersection Over Union Tests:")
    unittest.main()