#include <Commands/PneumaticsAutoClose.h>

PneumaticsAutoClose::PneumaticsAutoClose(bool left, bool right)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::gripperArm);
	timer = new Timer();
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	PneumaticsDone = false;
	leftArm = left;
	rightArm = right;
}

// Called just before this Command runs the first time
void PneumaticsAutoClose::Initialize()
{
	time_timer = 0;
	time_run = 0;
	timer->Reset();
	timer->Start();
	PneumaticsDone = false;
}

// Called repeatedly when this Command is scheduled to run
void PneumaticsAutoClose::Execute()
{
	time_timer = timer->Get();
	if(time_timer >= time_run)
	{
		PneumaticsDone = true;
	}
	else
	{
		PneumaticsDone = false;
	}
	if(leftArm == true)
	{
		Robot::gripperArm->leftGripper->Set(Robot::gripperArm->leftGripper->kForward);
	}
	if(rightArm == true)
	{
		Robot::gripperArm->rightGripper->Set(Robot::gripperArm->rightGripper->kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PneumaticsAutoClose::IsFinished()
{
	return PneumaticsDone;
}

// Called once after isFinished returns true
void PneumaticsAutoClose::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PneumaticsAutoClose::Interrupted()
{

}
