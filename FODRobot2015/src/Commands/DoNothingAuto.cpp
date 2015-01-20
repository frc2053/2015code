#include "DoNothingAuto.h"

DoNothingAuto::DoNothingAuto()
{
	Requires(Robot::driveBaseSub);
	time_timer = 0;
	time_run = 15;
	timer = new Timer();
	NothingDone = false;
}

// Called just before this Command runs the first time
void DoNothingAuto::Initialize()
{
	time_timer = 0;
	time_run = 15;
	timer = 0;
	timer->Reset();
	timer->Start();
	NothingDone = false;
}

// Called repeatedly when this Command is scheduled to run
void DoNothingAuto::Execute()
{
	Robot::driveBaseSub->MechDrive(0,0,0,0);
	time_timer = timer->Get();
	if(time_timer >= time_run)
	{
		NothingDone = true;
	}
	else
	{
		NothingDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DoNothingAuto::IsFinished()
{
	return NothingDone;
}

// Called once after isFinished returns true
void DoNothingAuto::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothingAuto::Interrupted()
{

}
