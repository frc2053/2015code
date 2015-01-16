#include "GrabNGoAuto.h"
#include "driveAuto.h"
#include "PneumaticsAutoClose.h"
#include "PneumaticsAutoOpen.h"

GrabNGoAuto::GrabNGoAuto()
{
	//side, fow, rot, yaw, time
	AddSequential(new PneumaticsAutoClose(true, true));

	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2));

	AddSequential(new PneumaticsAutoOpen(true, true));
}
