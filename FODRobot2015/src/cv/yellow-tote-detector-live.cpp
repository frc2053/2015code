#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "YellowToteFinder.h"

using namespace cv;
using namespace std;

/** @function main */
int main( int argc, char** argv )
{   
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat frame;
    YellowToteFinder ytf = YellowToteFinder();
    bool isMatch;
    for(;;)
    {        
        cap >> frame; // get a new frame from camera
        isMatch = ytf.findTote(&frame);
        
        // Mask all except yellow :)
        Mat hsvImg, maskImg, masked;
        cvtColor(frame, hsvImg, CV_BGR2HSV);
        Scalar hsvMin = Scalar(20, 100, 100);
        Scalar hsvMax = Scalar(30, 255, 255);
        inRange(hsvImg, hsvMin, hsvMax, maskImg);
        frame.copyTo(frame, maskImg);
        
        if(isMatch) {
            cout << "Distance From Tote: " << ytf.getDistanceToTote() << "    Dist OFFSET = " << ytf.getOffsetDistance(&frame) << endl;
            drawContour(&ytf.contourTote, &frame);
        }        
        
        imshow("Masked", maskImg);
        imshow("Yellow Tote Detector Line - Src", frame);
        if(waitKey(30) >= 0) break;
        //usleep(100000);
    }
    return 0;
}

