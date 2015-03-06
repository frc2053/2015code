#include "PneumaticsAuto.h"
#include "FullAutoWide.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "RotatetoAngle.h"
#include "DriveWhileWinching.h"
#include "Commands/SetOffSet.h"
FullAutoWide::FullAutoWide()
{
	AddSequential(new SetOffSet(180));
	//driveAuto(side, fow, rot, yaw, time)
	//WinchAuto(speed, time)
	//PneumaticsAuto(left, right, close = true open = false);

	//printf("Auto Wide 0\n");
	//grabs first tote
	AddSequential(new PneumaticsAuto(true, true, true));
	//printf("Auto Wide 1\n");
	//drives back from first tote while winching
	AddSequential(new DriveWhileWinching(0.0, 0.2, 0.0, 0.0, 1, 0.5, 1));
	////printf("Auto Wide 1.5\n");
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0));
	//printf("Auto Wide 2\n");
	//driving to second tote
	AddSequential(new driveAuto(0.2, 0.0, 0.0, 0.0, 1));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.2));
	//printf("Auto Wide 3\n");
	//drives forward to second tote
	AddSequential(new driveAuto(0.0, -0.2, 0.0, 0.0, 1));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.2));
	//printf("Auto Wide 4\n");
	//drops first tote on second tote
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("Auto Wide 5\n");
	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.2, -0.2, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0));
	//printf("Auto Wide 6\n");
	//grabs second tote
	AddSequential(new PneumaticsAuto(true, true, true));
	//printf("Auto Wide 7\n");
	//drives backwards from second tote while winching
	AddSequential(new DriveWhileWinching(0.0, 0.2, 0.0, 0.0, 1, 0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0));
	//printf("Auto Wide 8\n");
	//drives to third tote
	AddSequential(new driveAuto(0.2, 0.0, 0.0, 0.0, 1));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.2));
	//printf("Auto Wide 9\n");
	//drives forward to third tote
	AddSequential(new driveAuto(0.0, -0.2, 0.0, 0.0, 1));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.2));
	//printf("Auto Wide 10\n");
	//drops first tote stack on third tote
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("Auto Wide 11\n");
	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, -0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0));
	//printf("Auto Wide 12\n");
	//grabs third tote
	AddSequential(new PneumaticsAuto(true, true, true));
	//printf("Auto Wide 13\n");
	//drives backwards
	AddSequential(new driveAuto(0.0, 0.2, 0.0, 0.0, 5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.2));
	//printf("Auto Wide 14\n");
	//drops totes
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("Auto Wide 15\n");
}
