#ifndef __UTILS_H__
#define __UTILS_H__

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "HsvRange.h"

using namespace cv;

extern RNG rng;

#define randColor()     Scalar(rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255))

extern Scalar GREEN;
extern Scalar RED;
extern Scalar BLUE;
extern Scalar YELLOW;

extern HsvRange HSV_YELLOW;

void drawRectangle(Mat *img, Rect *rect, Scalar *color);
void drawPoint(Mat *img, Point *p, Scalar *color);

#endif
