# Understanding Bounding Box Coordinate Formats


💡 There are two types of bounding box (bbox) coordinate formats: **mid-point** and **corner-points**.

### Vocab:

**Absolute pixel values:** The coordinate values of bounding boxes are in pixel measurements. Fixed to image resolution *e.g. x = 10 pixels; Doesn't resize well.*

**Percentage values (Normalized):** The coordinate values of bounding boxes are in percentages normalized (0-1 scale) of the image dimensions *e.g. x = 0.10; Scales automatically with image resizing.*

Both **mid-points** and **corner-points** can have values of either absolute values or percentage values. *Certain scenarios* require them to be in one or the other. But for the most part -> Deep Learning Models when training (Input/Output): Normalized values are overwhelmingly preferred for both mid-point and corner-point formats. In cases like plotting bounding boxes its easier to use absolute values.


### Mid-point format: `(x, y, w, h)`  

* The `x`, `y` represent the (mid/center) point of the bounding box. 

    <img src="./showcase_images/bbox-x-y.png" width="100px">
* `w` and `h` represent the width and height of the bounding box.

    <img src="./showcase_images/bbox-w-h.png" width="100px">

### Corner-points format: `(x_min, y_min, x_max, y_max)`  

* Can also be noted as `(x₁, y₁, x₂, y₂)`.
* `x_min`, `y_min` represents the top-left corner of the bounding box.  

* `x_max`, `y_max` represent the bottom-right corner.  

    <img src="./showcase_images/corners.png" width="100px">
* These coordinates are typically relative to the **entire image**.
* Corner-points is often used during postprocessing steps such as **IoU calculation**, **visualization**, and **Non-Max-Suppression**.

### Easily Resize-able

* It does not matter whether the bounding box coordinates are represented as **corner-points** (x₁, y₁, x₂, y₂) or **mid-points** (x, y, w, h) as long as they are expressed as **percentages** (normalized values between 0 and 1) and relative to the entire image dimensions you can resize any image without having to worry about messing up the bounding box coordinates.

### How To Convert Between Formats

***Note:** Examples use absolute pixel values, but the same conversion formulas apply for both absolute pixel values and percentage coordinates.*


**Corner-points to midpoints: ↓**

<img src="./showcase_images/converting_corner_points_to_mid_points.png" >