#include "GrabNGoAuto.h"
#include "driveAuto.h"

GrabNGoAuto::GrabNGoAuto()
{
	//side, fow, rot, yaw, time


	AddSequential(new driveAuto(0.0, 0.5, 0.0, 0.0, 2));
}
