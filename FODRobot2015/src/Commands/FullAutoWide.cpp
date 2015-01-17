#include "FullAutoWide.h"
#include "driveAuto.h"
#include "PneumaticsAutoClose.h"
#include "PneumaticsAutoOpen.h"
#include "WinchAuto.h"
#include "RotatetoAngle.h"
#include "DriveWhileWinching.h"

FullAutoWide::FullAutoWide()
{
	//driveAuto(side, fow, rot, yaw, time)
	//WinchAuto(speed, time)
	//PneumaticsAuto(left, right);

	printf("0");
	//grabs first tote
	AddSequential(new PneumaticsAutoClose(true, true));
	printf("1");
	//drives back from first tote while winching
	AddSequential(new DriveWhileWinching(0.0, -0.5, 0.0, 0.0, 0.5, 0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("2");
	//driving to second tote
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));
	printf("3");
	//drives forward to second tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));
	printf("4");
	//drops first tote on second tote
	AddSequential(new PneumaticsAutoOpen(true, true));
	printf("5");
	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, -0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("6");
	//grabs second tote
	AddSequential(new PneumaticsAutoClose(true, true));
	printf("7");
	//drives backwards from second tote while winching
	AddSequential(new DriveWhileWinching(0.0, 0.5, 0.0, 0.0, 0.5, 0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("8");
	//drives to third tote
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));
	printf("9");
	//drives forward to third tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));
	printf("10");
	//drops first tote stack on third tote
	AddSequential(new PneumaticsAutoOpen(true, true));
	printf("11");
	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, -0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	printf("12");
	//grabs third tote
	AddSequential(new PneumaticsAutoClose(true, true));
	printf("13");
	//drives backwards
	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 2));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));
	printf("14");
	//drops totes
	AddSequential(new PneumaticsAutoOpen(true, true));
	printf("15");
}
