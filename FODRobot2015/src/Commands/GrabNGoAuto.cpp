#include <Commands/PneumaticsAuto.h>
#include "GrabNGoAuto.h"
#include "DriveWhileWinching.h"
#include "PneumaticsAuto.h"

GrabNGoAuto::GrabNGoAuto()
{
	//FALSE IS CLOSE, TRUE IS OPEN
	//printf("grabandgoauto 0\n");
	//side, fow, rot, yaw, time
	AddSequential(new PneumaticsAuto(true, true, false));
	//printf("grabandgoauto 1\n");
	AddSequential(new DriveWhileWinching(0.0, -0.5, 0.0, 0.0, 2, 0.5, 1));
	//printf("grabandgoauto 2\n");
	AddSequential(new PneumaticsAuto(true, true, true));
	//printf("grabandgoauto 3\n");
}
//robot.run
