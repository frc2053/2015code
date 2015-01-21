#include <Commands/PneumaticsAuto.h>
#include "GrabNGoAuto.h"
#include "driveAuto.h"
#include "PneumaticsAuto.h"

GrabNGoAuto::GrabNGoAuto()
{
	//side, fow, rot, yaw, time
	AddSequential(new PneumaticsAuto(true, true, true));

	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2));

	AddSequential(new PneumaticsAuto(true, true, false));
}
