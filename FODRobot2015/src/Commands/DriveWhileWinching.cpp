#include "DriveWhileWinching.h"
#include "driveAuto.h"
#include "WinchAuto.h"

DriveWhileWinching::DriveWhileWinching(double side, double fow, double rot, double yaw, double time, double speedWinch, double timeWinch)
{
	printf("DriveWhileWinching 0\n");
	AddParallel(new driveAuto(side, fow, rot,  yaw, time));
	printf("DriveWhileWinching 1\n");
	AddParallel(new WinchAuto(speedWinch, timeWinch));
	printf("DriveWhileWinching 2\n");
}
