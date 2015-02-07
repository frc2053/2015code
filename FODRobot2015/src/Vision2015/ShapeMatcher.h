#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Contour.h"
#include "HsvRange.h"

using namespace std;
using namespace cv;

#define MIN_CONTOUR_SIZE    6
#define MIN_OBJ_WH          20

class ShapeMatcher
{
protected:
    HsvRange *matchColor;
    
    virtual bool isMatch(Contour *contour, Mat *img) { return false; }
    
public:
    bool debugDraw;
    
    ShapeMatcher();
    ShapeMatcher(HsvRange* matchColor);
    bool findMatch(vector<Contour> *contours, Mat *img, Contour *matchingContour, cv::Rect *boundingRect);
};

/***** BackwardsLMatcher *****/
class BackwardsLMatcher: public ShapeMatcher
{
private:
    bool isMatch(Contour *contour, Mat *img);
public:
    BackwardsLMatcher(HsvRange* matchColor) : ShapeMatcher(matchColor) {}
};

/***** LMatcher *****/
class LMatcher: public ShapeMatcher
{
private:
    bool isMatch(Contour *contour, Mat *img);
public:
    LMatcher(HsvRange* matchColor) : ShapeMatcher(matchColor) {}
};

/***** YellowToteMatcher *****/
class YellowToteMatcher: public ShapeMatcher
{
private:
    bool isMatch(Contour *contour, Mat *img);
public:
    YellowToteMatcher(HsvRange* matchColor) : ShapeMatcher(matchColor) {}
};

