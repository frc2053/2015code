#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

#include "ShapeMatcher.h"
#include "Contour.h"
#include "utils.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{   
    /// Load & prep src image
    Mat src, drawing;
    src = imread( argv[1], 1 );
    drawing = Mat::zeros(src.size(), CV_8UC3);
    bool isMatch, isMatch2;
    vector<Contour> contours = detectContoursColorFiltered(&src, &HSV_YELLOW,6, 25);
    BackwardsLMatcher blm(NULL);
    LMatcher lm(NULL);
    
    drawContourList(&contours, &drawing);
    
    for(int i=0; i < contours.size(); i++)
        contourDrawPoints(&contours[i], &drawing);
    
    Contour matchingContour, matchingContour2;
    Rect matchingBoundRect, matchingBoundRect2;
    isMatch = blm.findMatch(&contours, &src, &matchingContour, &matchingBoundRect);
    isMatch2 = lm.findMatch(&contours, &src, &matchingContour2, &matchingBoundRect2);
    
    if (isMatch && isMatch2) {
        float dist = 4740.0 / matchingBoundRect.width;
        cout << "Distance is " << dist << endl;
        
        // Estimate dist from center
        float leftL_RightMostX = matchingBoundRect.x + matchingBoundRect.width;
        float rightL_LeftMostX = matchingBoundRect2.x;
        float toteCenterX = (leftL_RightMostX + rightL_LeftMostX) / 2;
        float frameCenter = src.cols/2;
        float toteDeltaPix = frameCenter - toteCenterX;
        
        Point p = Point(toteCenterX, 100);
        Point p2 = Point(frameCenter, 100);
        drawPoint(&src, &p, &BLUE);
        drawPoint(&src, &p2, &RED);
        
        float pixPer7Inches = matchingBoundRect.width; // pixels in 7 inches
        float toteDeltaInches = toteDeltaPix / (pixPer7Inches/7);
        cout << "toteDeltaInches = " << toteDeltaInches << endl;
    }
    
    /// Show in a window
    imshow( "Contours", drawing );
    imshow( "Src", src );
    
    waitKey(0);
    return 0;
}

