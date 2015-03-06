#include "DoNothingAuto.h"
#include "Commands/SetOffSet.h"
DoNothingAuto::DoNothingAuto()
{
	Requires(Robot::driveBaseSub);
	time_timer = 0;
	time_run = 15;
	timer = new Timer();
	NothingDone = false;
	//printf("do nothing auto const\n");

}

// Called just before this Command runs the first time
void DoNothingAuto::Initialize()
{
	time_timer = 0;
	time_run = 15;
	timer->Reset();
	timer->Start();
	NothingDone = false;
	//printf("do nothing auto init\n");
}

// Called repeatedly when this Command is scheduled to run
void DoNothingAuto::Execute()
{
	time_timer = timer->Get();
	//printf("timer %3.2f" ,time_timer);
	if(time_timer >= time_run)
	{
		NothingDone = true;
	}
	else
	{
		NothingDone = false;
	}
	//printf("do nothing auto execute\n");
}

// Make this return true when this Command no longer needs to run execute()
bool DoNothingAuto::IsFinished()
{
	//printf("do nothing auto finished\n");
	return NothingDone;
}

// Called once after isFinished returns true
void DoNothingAuto::End()
{
	//printf("do nothing auto end\n");
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothingAuto::Interrupted()
{
	//printf("do nothing auto interrupted");
}
