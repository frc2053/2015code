#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "YellowToteFinder.h"
#include "Contour.h"

YellowToteFinder::YellowToteFinder()
{
}

bool YellowToteFinder::findTote(Mat* img)
{   
    vector<Contour> contours = detectContoursColorFiltered(img, &HSV_YELLOW, 6, 25);
    
    // Find Shapes
    foundTote = ytm.findMatch(&contours, img, &contourTote, &rectTote);
    //foundL = lm.findMatch(&contours, img, &contourL, &rectL);
    //foundBL = blm.findMatch(&contours, img, &contourBL, &rectBL);
    
    // Check for proper nesting
    //checkNesting();
    
    // If we have an L but no tote, infer size/location of tote.
    //if (!foundTote && (foundL || foundBL))
    //    inferToteLocation();
    
    cout << "Found (" << foundTote << ")" << endl;
    //cout << "Found (" << foundTote << "," << foundBL << "," << foundL << ")" << endl;
    //cout << "Properly Nested? " << isProperlyNested << endl;
    
    // If we're missing the tote, try to infer the tote's position from the L's.
    
    /*
     1. Found tote, L, BL & They are properly nested: Good :)
     2. Found L, BL, missing Tote or bad nesting, trust L's infer shape of tote
     3. Found one L, found tote & properly nested: Good :)
     4. Found one L, missing l and tote: Assume location of tote based on L.
    */
    
    return foundTote;
}

void YellowToteFinder::checkNesting()
{
    // If there is no tote, we only need to see if the L's are not nested.
    if (!foundTote) {
        
        // We are missing tote and an L. No nesting is possible. Assume it is ok.
        if (!foundL || !foundBL) {
            isProperlyNested = true;
            return;
        }
        
        // We have two L's - If they are nested, that is BAD. Just assume we never found them
        if (contourNested(&contourL, &contourBL) || contourNested(&contourBL, &contourL)) {
            foundL = foundBL = false;
            isProperlyNested = true;
            return;
        } 
        
        // L's are NOT nested,this is GOOD.
        isProperlyNested = true;
        return;
    }
    
    // We found a tote. Any L's we found should be nested in the tote
    else {
        
        // If we found both L's but neither are nested in tote, assume the tote is erroneous
        if (foundL && foundBL && !contourNested(&contourTote, &contourL) && !contourNested(&contourTote, &contourBL)) {
            foundTote = false;
            isProperlyNested = true;
            return;
        }
        
        // L is not in the tote. Ignore it.
        if (foundL && !contourNested(&contourTote, &contourL))
            foundL = false;
        
        // BL is not in the tote. Ignore it.
        if (foundBL && !contourNested(&contourTote, &contourBL))
            foundBL = false;
        
        isProperlyNested = true;
        return;
    }  
}


float YellowToteFinder::getDistanceToTote()
{
    // Actual dimensions: Long-side: 26.75, shoer-side: 16.75
    // THinkpad camera: 37.5 inches form tote: Long side width is 286 pixels
    // magic-constant = 35 * 400 = 14000
    //
    //
    
    float dist = 14000.0 / rectTote.width;
    cout << "rect.width = " << rectTote.width << endl;
    return dist;
}

float YellowToteFinder::getOffsetDistance(Mat* img)
{
    float toteCenterX = rectTote.x + rectTote.width/2;
    float frameCenter = img->cols/2;
    float toteDeltaPix = frameCenter - toteCenterX;

    Point p = Point(toteCenterX, 100);
    Point p2 = Point(frameCenter, 100);
    drawPoint(img, &p, &BLUE);
    drawPoint(img, &p2, &RED);

    //float dist = 10725.0 / toteDeltaPix;
    return toteDeltaPix;
}
