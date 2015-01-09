#include "GripperArm.h"
#include "../RobotMap.h"

GripperArm::GripperArm() : Subsystem("ExampleSubsystem")
{
	rightGripper = RobotMap::RightGripper;
	leftGripper = RobotMap::LeftGripper;
}

void GripperArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
