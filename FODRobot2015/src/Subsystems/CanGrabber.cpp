#include "CanGrabber.h"
#include "../RobotMap.h"
#include "Commands/CanGrab.h"

CanGrabber::CanGrabber() :
Subsystem("CanGrabber")
{
	flopperSolenoid = RobotMap::flopperSolenoid;
	wingSolenoid = RobotMap::wingSolenoid;
}

void CanGrabber::InitDefaultCommand()
{
	SetDefaultCommand(new CanGrab());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
