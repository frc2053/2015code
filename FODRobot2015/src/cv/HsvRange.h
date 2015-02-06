#ifndef __HSV_RANGE__
#define __HSV_RANGE__

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class HsvRange
{
    public:
        Scalar hsvMin;
        Scalar hsvMax;
        
        HsvRange(Scalar hsvMin, Scalar hsvMax);
        bool testPixel(Mat *hsvImg, int x, int y);
        int testPoints(Mat *hsvImg, vector<Point> *testPoints);
};

#endif
