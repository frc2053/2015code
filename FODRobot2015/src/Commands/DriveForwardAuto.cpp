#include "DriveForwardAuto.h"
#include "driveAuto.h"

DriveForwardAuto::DriveForwardAuto()
{
	//side, fow, rot, yaw, time
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2));
}
