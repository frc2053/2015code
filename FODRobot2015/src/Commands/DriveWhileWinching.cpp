#include "DriveWhileWinching.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "DriveAutoCorrect.h"
DriveWhileWinching::DriveWhileWinching(double side, double fow, double rot, double yaw, double time, double speedWinch, double timeWinch, double angle)
{
	//printf("DriveWhileWinching 0\n");
	AddParallel(new DriveAutoCorrect(side, fow, rot, yaw, time, angle));
	//printf("DriveWhileWinching 1\n");
	AddParallel(new WinchAuto(speedWinch, timeWinch));
	//printf("DriveWhileWinching 2\n");
}
