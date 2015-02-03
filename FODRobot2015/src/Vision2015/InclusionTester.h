#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Contour.h"

using namespace cv;

class InclusionTester
{
    public:
        InclusionTester(int numPoints, vector<bool> expectedAnswers);
        int test(Contour *contour);
        int test(Contour *contour, Mat *img);
    
    private:
        vector<Point> *testPoints;
        vector<bool> expectedAnswers;
        int numPoints;
        
        void generateTestPoints(Rect *boundRect);
        int checkPoints(Contour* contour);
        int checkAndDrawPoints(Contour* contour, Mat *img);
};
