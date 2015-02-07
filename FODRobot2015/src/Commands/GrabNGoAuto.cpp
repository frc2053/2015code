#include <Commands/PneumaticsAuto.h>
#include "GrabNGoAuto.h"
#include "driveAuto.h"
#include "PneumaticsAuto.h"

GrabNGoAuto::GrabNGoAuto()
{
	//printf("grabandgoauto 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new PneumaticsAuto(true, true, true));
	//printf("grabandgoauto 1\n");
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2));
	//printf("grabandgoauto 2\n");
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("grabandgoauto 3\n");
}
