#include "Pneumatics.h"

Pneumatics::Pneumatics()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::gripperArm);
	right_Bumper = false;
	left_Bumper = false;
	//printf("Pneumatics constructor\n");
}

// Called just before this Command runs the first time
void Pneumatics::Initialize()
{
	right_Bumper = false;
	left_Bumper = false;
	//printf("Pneumatics Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void Pneumatics::Execute()
{
	//printf("Pneumatics Execute\n");
	right_Bumper = Robot::oi->joystick2->GetRawButton(5);
	left_Bumper = Robot::oi->joystick2->GetRawButton(6);

	if(right_Bumper == true)
	{
		Robot::gripperArm->rightGripper->Set(Robot::gripperArm->rightGripper->kForward);
		Robot::gripperArm->leftGripper->Set(Robot::gripperArm->leftGripper->kForward);
	}
	if(left_Bumper == true)
	{
		Robot::gripperArm->rightGripper->Set(Robot::gripperArm->rightGripper->kReverse);
		Robot::gripperArm->leftGripper->Set(Robot::gripperArm->leftGripper->kReverse);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Pneumatics::IsFinished()
{
	//printf("Pneumatics is finished\n");
	return false;
}

// Called once after isFinished returns true
void Pneumatics::End()
{
	//printf("Pneumatics end\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pneumatics::Interrupted()
{
	//printf("Pneumatics interuppteed\n");
}
