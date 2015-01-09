#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() : Subsystem("ExampleSubsystem")
{
	winchJag = RobotMap::winchJag;
}

void Winch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
