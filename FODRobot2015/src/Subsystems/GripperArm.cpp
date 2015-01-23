#include "GripperArm.h"
#include "../RobotMap.h"
#include "../Commands/Pneumatics.h"

GripperArm::GripperArm() : Subsystem("GripperArm")
{
	rightGripper = RobotMap::RightGripper;
	leftGripper = RobotMap::LeftGripper;
	printf("GripperArmSub constructor\n");
}

void GripperArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Pneumatics());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
