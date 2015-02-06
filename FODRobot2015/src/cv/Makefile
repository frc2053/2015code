# Notes:
# $< - Name of first prereq: So for utils.o, this resolves to utils.cpp
#
#

DEBUG = 1       # Comment out to compile optimized without debug symbols
#BUILD_ARM = 1   # Comment out to NOT build arm executables

X86_CFLAGS = `pkg-config --cflags opencv`  -std=c++11
X86_LDFLAGS = `pkg-config --libs opencv`

ARM_CFLAGS = -std=c++11 -I/home/jason/cv/arm/include/OpenCV
ARM_LDFLAGS = -L/home/jason/cv/arm/libs/opencv -lopencv_core -lopencv_imgproc -lopencv_highgui -Wl,-rpath=/home/jason/cv/arm/libs/opencv -lz -ltbb

MYLIBS = utils.o HsvRange.o Contour.o InclusionTester.o ShapeMatcher.o YellowToteFinder.o
MYPROGS = vidcap edge-detect-contour-explorer tape-detector tape-detector-live polygon-explorer-yellow yellow-tote-detector yellow-tote-detector-live yellow-mask-viewer snapshot

# Set compiler and flags for arch
ifdef BUILD_ARM
CPP = arm-frc-linux-gnueabi-g++
CFLAGS = $(ARM_CFLAGS)
LDFLAGS =  $(ARM_LDFLAGS)
else
CPP = g++
CFLAGS = $(X86_CFLAGS)
LDFLAGS = $(X86_LDFLAGS)
endif

## Set Debug ##
ifdef DEBUG
CFLAGS += -g
ARMCFLAGS += -g
else
CFLAGS += -O2
ARMCFLAGS += -O2
endif

all: $(MYLIBS) $(MYPROGS)

clean:
	rm -f $(MYLIBS)
	rm -f $(MYPROGS) 

##### Libraries #####
utils.o: utils.cpp
	$(CPP) -c $<  $(CFLAGS)

HsvRange.o: HsvRange.cpp
	$(CPP) -c $<  $(CFLAGS)
	
Contour.o: Contour.cpp Contour.h utils.o HsvRange.o
	$(CPP) -c $< $(CFLAGS)

InclusionTester.o: InclusionTester.cpp InclusionTester.h utils.o Contour.o
	$(CPP) -c $< $(CFLAGS)
	
ShapeMatcher.o: ShapeMatcher.cpp ShapeMatcher.h utils.o Contour.o InclusionTester.o
	$(CPP) -c $< $(CFLAGS)

YellowToteFinder.o: YellowToteFinder.cpp YellowToteFinder.h ShapeMatcher.cpp ShapeMatcher.h utils.cpp utils.h Contour.cpp Contour.h
	$(CPP) -c $< $(CFLAGS)
    
##### Programs #####

snapshot: snapshot.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LDFLAGS)
		
vidcap: vidcap.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LDFLAGS)

edge-detect-contour-explorer: edge-detect-contour-explorer.cpp $(MYLIBS)
	$(CPP) $< $(MYLIBS) -o $@ $(CFLAGS) $(LDFLAGS)

tape-detector: tape-detector.cpp $(MYLIBS)
	$(CPP) $< $(MYLIBS) -o $@ $(CFLAGS) $(LDFLAGS)

tape-detector-live: tape-detector-live.cpp $(MYLIBS)
	$(CPP) $< $(MYLIBS) -o $@ $(CFLAGS) $(LDFLAGS)

yellow-tote-detector: yellow-tote-detector.cpp $(MYLIBS)
	$(CPP) $< $(MYLIBS) -o $@ $(CFLAGS) $(LDFLAGS)

yellow-tote-detector-live: yellow-tote-detector-live.cpp $(MYLIBS)
	$(CPP) $< $(MYLIBS) -o $@ $(CFLAGS) $(LDFLAGS)

polygon-explorer-yellow: polygon-explorer-yellow.cpp $(MYLIBS)
	$(CPP) $< -o $@ $(MYLIBS) $(CFLAGS) $(LDFLAGS)

yellow-mask-viewer: yellow-mask-viewer.cpp $(MYLIBS)
	$(CPP) $< -o $@ $(MYLIBS) $(CFLAGS) $(LDFLAGS)

