/*
 * polygon-explorer-yellow path/to/img.jpg
 * 
 * Displays interesting polygons detcted within the given image based on
 * yellow filtering.
 *
*/

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
    Mat srcImg, hsvImg, srcCopy, contourImg, blankImg;
    vector<Contour> contours;
    vector<Vec4i> hierarchy;
    
    srcImg = imread( argv[1], 1 );
    
    // **** Yellow Filter **** //
    
    contours = detectContoursColorFiltered(&srcImg, &HSV_YELLOW,6, 25);
    
    // Draw contours
    contourImg = Mat::zeros(srcImg.size(), CV_8UC3);
    for(int i=0; i < contours.size(); i++) {
        Contour contour = contours[i];
        Rect boundRect = boundingRect(contour);
        
        drawContours(contourImg, contours, i, randColor(), 2);
        
        if (boundRect.height > 100 && boundRect.width > 100) {
            contourDrawLines(&contour, "Contour-" + to_string(i), srcImg.size());
            
            blankImg = Mat::zeros(srcImg.size(), CV_8UC3);
            contourInclusionTest(&contour, "ApproxPolyPoints-" + to_string(i), srcImg.size());
        }
    }
    
    imshow( "Contours", contourImg );
    imshow( "Src", srcImg );
    
    waitKey(0);
    return 0;
}
