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

	//grabs first tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives back from first tote while winching
	AddSequential(new DriveWhileWinching(0.0, 0.5, 0.0, 0.0, 0.5, 0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	//driving to second tote
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drives forward to second tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops first tote on second tote
	AddSequential(new PneumaticsAutoOpen(true, true));

	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, -0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	//grabs second tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives backwards from second tote while winching
	AddSequential(new DriveWhileWinching(0.0, 0.5, 0.0, 0.0, 0.5, 0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	//drives to third tote
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drives forward to third tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops first tote stack on third tote
	AddSequential(new PneumaticsAutoOpen(true, true));

	//lowers winch to first level
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, -0.5, 1));
	AddSequential(new DriveWhileWinching(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

	//grabs third tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives backwards
	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 2));
	AddSequential(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops totes
	AddSequential(new PneumaticsAutoOpen(true, true));
}
