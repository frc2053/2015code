#include "Winch.h"
#include "../RobotMap.h"
#include "../Commands/WinchControl.h"

Winch::Winch() : Subsystem("Winch")
{
	winchJag = RobotMap::winchJag;
}

void Winch::InitDefaultCommand()
{
	SetDefaultCommand(new WinchControl());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Winch::WinchMotor(float speed) {
	Robot::winch->winchJag->Set(speed);
}

