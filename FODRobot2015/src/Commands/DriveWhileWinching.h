#ifndef DriveWhileWinching_H
#define DriveWhileWinching_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class DriveWhileWinching: public CommandGroup
{
public:
	DriveWhileWinching(double side, double fow, double rot, double yaw, double time, double speedWinch, double timeWinch);
};

#endif
