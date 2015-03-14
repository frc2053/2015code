#include <Commands/PneumaticsAuto.h>
#include "GrabNGoAuto.h"
#include "DriveWhileWinching.h"
#include "PneumaticsAuto.h"
#include "WinchAuto.h"
#include "SetOffSet.h"
GrabNGoAuto::GrabNGoAuto()
{
	//DriveWhileWinching(side, fow, rot, yaw, time, winch speed, winch time, angle);
	//FALSE IS CLOSE, TRUE IS OPEN
	printf("grabandgoauto 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("grabandgoauto 1\n");
	AddSequential(new DriveWhileWinching(0.0, 0.5, 0.0, Robot::driveBaseSub->getAdjYaw(), 2.2, 1, 1, 0));
	//printf("grabandgoauto 2\n");
	//printf("grabandgoauto 3\n");
	AddSequential(new SetOffSet(180));
}
//robot.run
