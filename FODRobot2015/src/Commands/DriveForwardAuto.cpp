#include "DriveForwardAuto.h"
#include "driveAuto.h"
#include "Commands/SetOffSet.h"
#include "Commands/DriveAutoCorrect.h"
DriveForwardAuto::DriveForwardAuto()
{
	AddSequential(new SetOffSet(0));
	//printf("DriveFowAutoGroup 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new DriveAutoCorrect(0.0, -0.5, 0.0, Robot::driveBaseSub->getAdjYaw(), 2.3, 0));
	printf("DriveFowAutoGroup 1\n");
}
