#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "utils.h"

using namespace cv;

RNG rng = RNG(12344);

Scalar GREEN = Scalar(0,255,0);
Scalar RED   = Scalar(0,0,255);
Scalar BLUE   = Scalar(255,0,0);
Scalar YELLOW = Scalar(0,200,255);

// Hsv Colors
//HsvRange HSV_YELLOW = HsvRange(Scalar(20, 100, 100), Scalar(30, 255, 255));
// This as our original yellow range: Was missing quite a bit of the totes in frc-images
 
// New/experimental yellow. Picks up way more reflections in our images, but does better
// with frc images.
HsvRange HSV_YELLOW = HsvRange(Scalar(20, 80, 80), Scalar(30, 255, 255));


void drawRectangle(Mat *img, Rect *rect, Scalar *color)
{
    rectangle(*img, rect->tl(), rect->br(), *color, 2);
}

void drawPoint(Mat *img, Point *p, Scalar *color)
{
    cv::line(*img, *p, *p, *color, 2);
}
