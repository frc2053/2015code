#include "DriveWhileWinching.h"
#include "driveAuto.h"
#include "WinchAuto.h"

DriveWhileWinching::DriveWhileWinching(double side, double fow, double rot, double yaw, double time, double speedWinch, double timeWinch)
{
	AddParallel(new driveAuto(side, fow, rot,  yaw, time));
	AddParallel(new WinchAuto(speedWinch, timeWinch));
}
