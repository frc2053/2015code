#include "ShapeMatcher.h"
#include "InclusionTester.h"
#include "utils.h"

using namespace cv;
using namespace std;

ShapeMatcher::ShapeMatcher(HsvRange* matchColor)
{
    this->matchColor = matchColor;
    this->debugDraw = false;
}

bool ShapeMatcher::findMatch(vector<Contour> *contours, Mat *img, Contour *matchingContour, Rect *matchingBoundRect)
{
    for(int i=0; i < contours->size(); i++) {
        Contour *contour = &((*contours)[i]);
        Rect rect = boundingRect(Mat(*contour));
        
        // Is this shape an L shape?
        bool isL = isMatch(contour, img);
        if (!isL) continue;
        
        // If this is the L shape we're looking for, draw green rectangle (and shape end-points) on source image!
        if (this->debugDraw) {
            drawRectangle(img, &rect, &GREEN);
            contourDrawPoints(contour, img);
        }
        
        *matchingContour = *contour;
        *matchingBoundRect = rect;
        return true;
        
    }
    return false;

}   

/***** BackwardsLMatcher *****/

bool BackwardsLMatcher::isMatch(Contour *contour, Mat *img)
{   
    vector<bool> expectedAnswers { false, false, true,
                                   false, false, true,
                                   true,  true,  true
                                   };
    
    InclusionTester it(3, expectedAnswers);
    int matches = it.test(contour, img);
    return (matches == 9);
}

/***** LMatcher *****/

bool LMatcher::isMatch(Contour *contour, Mat *img)
{   
    vector<bool> expectedAnswers { true, false, false,
                                   true, false, false,
                                   true, true,  true
                                   };
    
    InclusionTester it(3, expectedAnswers);
    int matches = it.test(contour, img);
    return (matches == 9);
}

/***** YellowToteMatcher *****/

bool YellowToteMatcher::isMatch(Contour *contour, Mat *img)
{   
    // Can't use inclusion tester here because the tote has angles, it is not square.
    // We probably want to look at the angles at the edgles
    
    // Aspect ratio check
    /*
    Rect rect = boundingRect(Mat(*contour));
    float whRatio = (float)rect.width / rect.height;
    float whRatioMin =  1.2;
    float whRatioMax =  2.2;
    
    if (whRatio < whRatioMin ||  whRatio > whRatioMax) {
        //cout << "Rejecting shape based on aspect-ratio: " << whRatio << endl;
        return false;
    }
    */
    
    // Color check - Ensure a portion of the tote is the desired match color
    /*
    Mat hsvImg;
    cvtColor(*img, hsvImg, CV_BGR2HSV);
    
    vector<Point> testPoints(4);
    testPoints.push_back( Point(rect.x + rect.width/20, rect.y + rect.height/20) );
    testPoints.push_back( Point(rect.x + rect.width - rect.width/20, rect.y + rect.height/20) );
    testPoints.push_back( Point(rect.x + rect.width - rect.width/20, rect.y + rect.height - rect.height/20) );
    testPoints.push_back( Point(rect.x + rect.width/20, rect.y + rect.height - rect.height/20) );
    testPoints.push_back( Point(rect.x + rect.width/10, rect.y + rect.height/10) );
    testPoints.push_back( Point(rect.x + rect.width - rect.width/10, rect.y + rect.height/10) );
    testPoints.push_back( Point(rect.x + rect.width - rect.width/10, rect.y + rect.height - rect.height/10) );
    testPoints.push_back( Point(rect.x + rect.width/10, rect.y + rect.height - rect.height/10) );
    
    int matchFound = matchColor->testPoints(&hsvImg, &testPoints);    
    if (matchFound < 1) return false;
    */
    
    
    // Area check
    //double minArea = (rect.width * rect.height) * 0.55;
    //double area = contourArea(*contour, false);
    //cout << " Area is " << area << "   minArea=" << minArea << endl;
    //if (area < minArea) {
    //    cout << "AREA FAIL!\n";
    //    return false;
   // }
   
   // Perimiter check
   /*
   double rectP = (rect.width * 2) + (rect.height * 2); 
   double minP =  rectP * 0.75;
   double maxP =  rectP * 1.40;
   double p = arcLength(*contour,true);
   
   cout << "perim is: " << p << "    " << "minP=" << minP << "    maxP=" << maxP << endl;
   if (p > maxP) cout << "   FAILED max check!" << endl;
   if (p < minP) cout << "   FAILED min check!" << endl;
   */
   
   vector<bool> expectedAnswers { true, true, true,
                                  true, true, true,
                                  true, true,  true
                                };
    
    InclusionTester it(3, expectedAnswers);
    int matches = it.test(contour, img);
    return (matches >= 7);

}

