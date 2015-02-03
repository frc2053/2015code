#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Contour.h"
#include "utils.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{   
    Mat srcImg, hsvImg, maskImg, maskImg2, maskImg3, maskImg4;
    
    HsvRange HSV_YELLOW3 = HsvRange(Scalar(20, 80, 100), Scalar(30, 255, 255));
    HsvRange HSV_YELLOW4 = HsvRange(Scalar(20, 100, 80), Scalar(30, 255, 255));
    
    srcImg = imread( argv[1], 1 );
    cvtColor(srcImg, hsvImg, CV_BGR2HSV);
    inRange(hsvImg, HSV_YELLOW.hsvMin, HSV_YELLOW.hsvMax, maskImg);
    //inRange(hsvImg, HSV_YELLOW2.hsvMin, HSV_YELLOW2.hsvMax, maskImg2);
    inRange(hsvImg, HSV_YELLOW3.hsvMin, HSV_YELLOW3.hsvMax, maskImg3);
    inRange(hsvImg, HSV_YELLOW4.hsvMin, HSV_YELLOW4.hsvMax, maskImg4);
    
    imshow( "Src", srcImg );
    imshow( "Mask", maskImg );
    //imshow( "Mask2", maskImg2 );
    imshow( "Mask3", maskImg3 );
    imshow( "Mask4", maskImg4 );
    
    waitKey(0);
    return 0;
}
