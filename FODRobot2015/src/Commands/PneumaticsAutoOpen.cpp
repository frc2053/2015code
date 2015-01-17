#include "PneumaticsAutoOpen.h"

PneumaticsAutoOpen::PneumaticsAutoOpen(bool left, bool right)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::gripperArm);
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	timer = new Timer();
	PneumaticsDone = false;
	leftArm = left;
	rightArm = right;
	printf("PneumaticsAutoOpen 0");
}

// Called just before this Command runs the first time
void PneumaticsAutoOpen::Initialize()
{
	time_timer = 0;
	time_run = 0;
	timer = 0;
	timer->Reset();
	timer->Start();
	PneumaticsDone = false;
}

// Called repeatedly when this Command is scheduled to run
void PneumaticsAutoOpen::Execute()
{
	if(leftArm == true)
	{
		Robot::gripperArm->leftGripper->Set(Robot::gripperArm->leftGripper->kReverse);
	}
	if(rightArm == true)
	{
		Robot::gripperArm->rightGripper->Set(Robot::gripperArm->rightGripper->kReverse);
	}
	time_timer = timer->Get();
	if(time_timer >= time_run)
	{
		PneumaticsDone = true;
	}
	else
	{
		PneumaticsDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PneumaticsAutoOpen::IsFinished()
{
	return PneumaticsDone;
}

// Called once after isFinished returns true
void PneumaticsAutoOpen::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PneumaticsAutoOpen::Interrupted()
{

}
