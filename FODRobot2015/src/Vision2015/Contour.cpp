#include "Contour.h"
#include "utils.h"

/* Draw a single contour to the given matrix. */
void drawContour(Contour *contour, Mat *img)
{
    vector<Contour> contours(0);
    contours.push_back(*contour);
    
    Scalar color = Scalar( 200, 200, 100);
    drawContours(*img, contours, 0, color, 2);
}

/* contourDrawList(Contour*, String, Size sz)
 *     Draws each contour in the list in a separate random color. The reusults are
 *     displayed in a new window.
 * 
 * contourDrawLines(Contour*, String, Mat*)
 *     Same as above, but draws into the Matrix the caller provides and does not
 *     display the result in a window.
 *
 * If called in a loop winTitle should be something like:
 *     "ContourPoints-" + to_string(i)  
 * to avoid duplicate window names.
 *
 * sz - Size of the Mat to create. Get this from your source image:
 *     srcMat.size()
*/

void contourDrawList(vector<Contour> *contourList, String winTitle, Size sz)
{
    Mat img(sz, CV_8UC3);
    
    drawContourList(contourList, &img);
    imshow(winTitle, img);
}

void drawContourList(vector<Contour> *contourList, Mat *img)
{
    for (int i=0; i < contourList->size(); i++) {
        drawContours(*img, *contourList, i, randColor(), 2);
    }
}

/* contourDrawPoints(Contour*, String, Size sz)
 *     Draws and Displays a point for each point within a contour
 *     in a new window.  All points are drawn in redish color.
 * 
 * contourDrawPoints(Contour*, String, Mat*)
 *     Same as above, but draws into the Matrix the caller provides and does not
 *     display the result in a window.
 *
 * If called in a loop winTitle should be something like:
 *     "ContourPoints-" + to_string(i)  
 * to avoid duplicate window names.
 *
 * sz - Size of the Mat to create. Get this from your source image:
 *     srcMat.size()
*/

void contourDrawPoints(Contour *contour, String winTitle, Size sz)
{
    Mat img(sz, CV_32FC3);
    
    contourDrawPoints(contour, &img);
    imshow(winTitle, img);
}

void contourDrawPoints(Contour *contour, Mat *img)
{
    Scalar color = Scalar( 0, 0, 255);
    int i;
    
    for (i=0; i < contour->size()-1; i++) {
        Point point = (*contour)[i];
        cv::line(*img, point, point, color, 2);
    }
}

/* contourDrawLines(Contour*, String, Size sz)
 *     Draws and Displays line segments connecting all the points within a contour
 *     in a new window. The lines are drawn between adjacent points within the
 *     contour vector, and a line is drawn from the last point to the first point
 *     to connect/close the shape created by the contour. All lines are drawn in
 *     a random color except for the final closing line which is red.
 * 
 * contourDrawLines(Contour*, String, Mat*)
 *     Same as above, but draws into the Matrix the caller provides and does not
 *     display the result in a window.
 *
 * If called in a loop winTitle should be something like:
 *     "ContourPoints-" + to_string(i)  
 * to avoid duplicate window names.
 *
 * sz - Size of the Mat to create. Get this from your source image:
 *     srcMat.size()
*/

void contourDrawLines(Contour *contour, String winTitle, Size sz)
{
    Mat img(sz, CV_32FC3);
    
    contourDrawLines(contour, &img);
    imshow(winTitle, img);
}

void contourDrawLines(Contour *contour, Mat *img)
{
    int i;
    
    for (i=0; i < contour->size()-1; i++) {
        Point point = (*contour)[i];
        Point point2 = (*contour)[i+1];
        
        cv::line(*img, point, point2, randColor(), 2);
    }
    cv::line(*img, (*contour)[i], (*contour)[0], Scalar(0,0,255), 2);
}

/* contourInclusionTest(Contour*, String, Size sz)
 *     Colors a new Matrix such that any inside the polygon created by the given
 *     contour will be gree, anything outside will be red and anything landing on
 *     an edge will be white.
 * 
 * contourInclusionTest(Contour*, String, Mat*)
 *     Same as above, but draws into the Matrix the caller provides and does not
 *     display the result in a window.
 *
 * If called in a loop winTitle should be something like:
 *     "ContourPoints-" + to_string(i)  
 * to avoid duplicate window names.
 *
 * sz - Size of the Mat to create. Get this from your source image:
 *     srcMat.size()
*/

void contourInclusionTest(Contour *contour, String winTitle, Size sz)
{
    Mat img(sz, CV_8UC3);
    
    contourInclusionTest(contour, &img);
    imshow(winTitle, img);
}

void contourInclusionTest(Contour *contour, Mat *img)
{
    int xMax = img->rows-1;
    int yMax = img->cols-1;
    
    for (int y=0; y <= yMax; y++) {
        for (int x=0; x <= xMax; x++) {
            Point point = Point(y,x);
            int rc = pointPolygonTest(*contour, point, false);
            if (rc < 0)
                cv::line(*img, point, point, Scalar(0,0,255), 1);
            else if (rc > 0)
                cv::line(*img, point, point, Scalar(0,255,0), 1);
            else
                cv::line(*img, point, point, Scalar(0,0,0), 1);
        }
    }
 
}

vector<Contour> detectContoursColorFiltered(Mat *img, HsvRange *hrange, int minPoints, int minLength)
{
    vector<Contour> contours, contoursApprox;
    Mat hsvImg, maskImg; 
    
    cvtColor(*img, hsvImg, CV_BGR2HSV);
    
    inRange(hsvImg, HSV_YELLOW.hsvMin, HSV_YELLOW.hsvMax, maskImg);
    findContours(maskImg, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    
    for(int i=0; i < contours.size(); i++) {
        Contour contour = contours[i];

        // Approximate polygonal shape
        Contour approxShape(contour.size());
        approxPolyDP(contour, approxShape, 3, true);
        
        // Reject contours wilth a very small size
        Rect rect = boundingRect(Mat(approxShape));
        if (rect.width < minLength || rect.height < minLength)
            continue;
        
        // Reject contours that don't have enough points to be the correct shape
        if (approxShape.size() < minPoints)
            continue;
            
        contoursApprox.push_back(contour);
    }
    return contoursApprox;
}

Point contourCentoid(Contour* contour)
{    
    Moments m = moments(*contour);
    int cx = m.m10/m.m00;
    int cy = m.m01/m.m00;
    return Point(cx, cy);
}

bool contourNested(Contour *parent, Contour *child)
{
    Point childCentoid = contourCentoid(child);
    int rc = pointPolygonTest(*parent, childCentoid, false);   
    return (rc >= 0);
}
