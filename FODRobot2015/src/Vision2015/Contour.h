#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "HsvRange.h"

using namespace cv;
	
typedef typename std::vector<cv::Point> Contour;

/*****  Contur Drawing Functions *****/

void drawContour(Contour *contour, Mat *img);

void drawContourList(vector<Contour> *contourList, Mat *img);
void drawContourList(vector<Contour> *contourList, String winTitle, Size sz);

void contourDrawPoints(Contour *contour, Mat *img);
void contourDrawPoints(Contour *contour, String winTitle, Size sz);

void contourDrawLines(Contour *contour, Mat *img);
void contourDrawLines(Contour *contour, String winTitle, Size sz);

void contourInclusionTest(Contour *contour, String winTitle, Size sz);
void contourInclusionTest(Contour *contour, Mat *img);

/***** Contour Detection *****/

vector<Contour> detectContoursColorFiltered(Mat *img, HsvRange *hrange, int minPoints, int minLength);

/***** Misc *****/

cv::Point contourCentoid(Contour* contour);
bool contourNested(Contour *parent, Contour *child);
