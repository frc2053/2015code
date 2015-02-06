/*
 * ./edge-detect-contour-explorer /path/toimg.jpg
 *
 * Show all contours (and their points) that are over a certain size.
 * This progrma uses canny edge detection to find contours.
*/

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Contour.h"
#include "utils.h"

using namespace cv;
using namespace std;

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;

#define MIN_CONTOUR_SIZE    10

/** @function main */
int main( int argc, char** argv )
{
    /// Load & prep src image
    src = imread( argv[1], 1 );
    cvtColor( src, src_gray, CV_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    
    /// Detect edges using canny
    Mat canny_output;
    Canny(src_gray, canny_output, 40, 40*2, 3);
    
    /// Find contours
    vector<Contour> contours;
    vector<Vec4i> hierarchy;
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    /// Draw contours
    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
    
    for(int i=0; i < contours.size(); i++) {
        if (contours[i].size() <= MIN_CONTOUR_SIZE) continue;
        drawContours(drawing, contours, i, randColor(), 2, 8, hierarchy, 0, Point());
        //drawContourPoints(drawing, contours[i]);
        contourDrawPoints(&contours[i], &drawing);
        
        Rect rect = boundingRect(Mat(contours[i]));
        rectangle(src, rect.tl(), rect.br(), randColor(), 2);
    }
    
    /// Show in a window
    namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
    imshow( "Contours", drawing );
    imshow( "Src", src );

    waitKey(0);
    return 0;
}

