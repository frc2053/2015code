#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ShapeMatcher.h"
#include "utils.h"
#include "Contour.h"

using namespace cv;
using namespace std;

/** @function main */
int main( int argc, char** argv )
{   
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    namedWindow("TapeFinder",1);

    Mat frame;
    BackwardsLMatcher blm(NULL);
    LMatcher lm(NULL);
    bool isMatch;
    for(;;)
    {        
        cap >> frame; // get a new frame from camera
            
        vector<Contour> contours = detectContoursColorFiltered(&frame, &HSV_YELLOW,6, 25);
        Contour matchingContour;
        Rect matchingBoundRect;
        
        blm.findMatch(&contours, &frame, &matchingContour, &matchingBoundRect);
        isMatch = lm.findMatch(&contours, &frame, &matchingContour, &matchingBoundRect);
        
        // Mask all except yellow :)
        Mat hsvImg, maskImg, masked;
        cvtColor(frame, hsvImg, CV_BGR2HSV);
        Scalar hsvMin = Scalar(20, 100, 100);
        Scalar hsvMax = Scalar(30, 255, 255);
        inRange(hsvImg, hsvMin, hsvMax, maskImg);
        frame.copyTo(frame, maskImg);
        
        // Estimate distance
        if(isMatch) {
            float dist = 4740.0 / matchingBoundRect.width;
            cout << "Distance is " << dist << endl;
            
            // Estimate dist from center
            float toteCenterX = matchingBoundRect.x + matchingBoundRect.width/2;
            float frameCenter = frame.rows/2;
            float toteDeltaPix = frameCenter - toteCenterX;
            
            float pixPer7Inches = matchingBoundRect.width; // pixels in 7 inches
            float toteDeltaInches = (toteDeltaPix * pixPer7Inches) / 7;
            cout << "toteDeltaPix " << toteDeltaPix << "   toteDeltaInches = " << toteDeltaInches << endl;
        }
        
        imshow("Src", frame);
        imshow("Masked", maskImg);
        if(waitKey(30) >= 0) break;
        //usleep(100000);
    }
    return 0;
}

