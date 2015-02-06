#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

#include "Contour.h"
#include "YellowToteFinder.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{   
    /// Load & prep src image
    Mat src;
    src = imread( argv[1], 1 );
    
    YellowToteFinder ytf = YellowToteFinder();
    bool isMatch = ytf.findTote(&src);
    
    if (ytf.foundTote) {
        drawContour(&ytf.contourTote, &src);
        cout << "Distance From Tote: " << ytf.getDistanceToTote() << "    Dist OFFSET = " << ytf.getOffsetDistance(&src) << endl;
    }
    //if (ytf.foundL) drawContour(&ytf.contourL, &src);
    //if (ytf.foundBL) drawContour(&ytf.contourBL, &src);

    imshow( "Src", src );    
    waitKey(0);
    return 0;
}

