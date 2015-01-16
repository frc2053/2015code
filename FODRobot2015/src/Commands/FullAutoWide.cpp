#include "FullAutoWide.h"
#include "driveAuto.h"
#include "PneumaticsAutoClose.h"
#include "PneumaticsAutoOpen.h"
#include "WinchAuto.h"
#include "RotatetoAngle.h"

FullAutoWide::FullAutoWide()
{
	//driveAuto(side, fow, rot, yaw, time)
	//WinchAuto(speed, time)
	//PneumaticsAuto(left, right);

	//grabs first tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives back from first tote
	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 0.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//raises winch to second level...
	AddParallel(new WinchAuto(0.5, 1));
	AddParallel(new WinchAuto(0.0, 0.0));

	//...while driving to second tote
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drives forward to second tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops first tote on second tote
	AddSequential(new PneumaticsAutoOpen(true, true));

	//lowers winch to first level
	AddSequential(new WinchAuto(-0.5, 1));
	AddParallel(new WinchAuto(0.0, 0.0));

	//grabs second tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives backwards from second tote
	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 0.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//raise winch to second level...
	AddParallel(new WinchAuto(0.5, 1));
	AddParallel(new WinchAuto(0.0, 0.0));

	//...while driving sideways
	AddSequential(new driveAuto(1, 0.0, 0.0, 0.0, 1.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drives forward to second tote
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 0.5));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops first tote stack on third tote
	AddSequential(new PneumaticsAutoOpen(true, true));

	//lowers winch to first level
	AddSequential(new WinchAuto(-0.5, 1));
	AddParallel(new WinchAuto(0.0, 0.0));

	//grabs third tote
	AddSequential(new PneumaticsAutoClose(true, true));

	//drives backwards
	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 2));
	AddParallel(new driveAuto(0.0, 0.0, 0.0, 0.0, 0.0));

	//drops totes
	AddSequential(new PneumaticsAutoOpen(true, true));
}
