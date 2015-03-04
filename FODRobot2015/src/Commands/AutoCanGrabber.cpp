#include "AutoCanGrabber.h"

AutoCanGrabber::AutoCanGrabber(bool wings, bool flopper, bool oc)
{
	Requires(Robot::canGrabber);
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	timer = new Timer();
	PneumaticsDone = false;
	wingopen = wings;
	flopperdown = flopper;
    open_close = oc;
}

// Called just before this Command runs the first time
void AutoCanGrabber::Initialize()
{
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	timer->Reset();
	timer->Start();
	PneumaticsDone = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoCanGrabber::Execute()
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
	if(open_close == true)
	{
		if(wingopen == true)
		{
			Robot::canGrabber->wingSolenoid->Set(Robot::canGrabber->wingSolenoid->kForward);
		}
		if(flopperdown == true)
		{
			Robot::canGrabber->flopperSolenoid->Set(Robot::canGrabber->flopperSolenoid->kForward);
		}
	}
	if(open_close == false)
	{
		if(wingopen == true)
		{
			Robot::canGrabber->wingSolenoid->Set(Robot::canGrabber->wingSolenoid->kReverse);
		}
		if(flopperdown == true)
		{
			Robot::canGrabber->flopperSolenoid->Set(Robot::canGrabber->flopperSolenoid->kReverse);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCanGrabber::IsFinished()
{
	return PneumaticsDone;
}

// Called once after isFinished returns true
void AutoCanGrabber::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCanGrabber::Interrupted()
{

}
