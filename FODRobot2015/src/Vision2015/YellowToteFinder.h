#include "Contour.h"
#include "ShapeMatcher.h"
#include "utils.h"

class YellowToteFinder
{       
private:
    YellowToteMatcher ytm = YellowToteMatcher(&HSV_YELLOW);
    BackwardsLMatcher blm = BackwardsLMatcher(NULL);
    LMatcher lm = LMatcher(NULL);
    
    void checkNesting();
    
public:
    bool foundTote, foundL, foundBL, isProperlyNested;
    Contour contourTote, contourL, contourBL;
    cv::Rect rectTote, rectL, rectBL;
    
    YellowToteFinder();
    bool findTote(Mat* img);
    float getDistanceToTote();
    float getOffsetDistance(Mat* img);
};
