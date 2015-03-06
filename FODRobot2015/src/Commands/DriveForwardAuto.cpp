#include "DriveForwardAuto.h"
#include "driveAuto.h"
#include "Commands/SetOffSet.h"
DriveForwardAuto::DriveForwardAuto()
{
	AddSequential(new SetOffSet(0));
	//printf("DriveFowAutoGroup 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2.1));
	printf("DriveFowAutoGroup 1\n");
}
