#include "DriveForwardAuto.h"
#include "driveAuto.h"

DriveForwardAuto::DriveForwardAuto()
{
	//printf("DriveFowAutoGroup 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new driveAuto(0.0, -0.5, 0.0, 0.0, 2));
	printf("DriveFowAutoGroup 1\n");
}
