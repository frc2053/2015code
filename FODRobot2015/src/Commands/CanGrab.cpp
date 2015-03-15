#include "CanGrab.h"

CanGrab::CanGrab()
{
	wing_toggle = false;
	flopper_toggle = false;
	wing_open = false;
	flopper_down = false;
	Requires(Robot::canGrabber);
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	timer = new Timer();
}

// Called just before this Command runs the first time
void CanGrab::Initialize()
{
	wing_toggle = false;
	flopper_toggle = false;
	wing_open = false;
	flopper_down = false;
	time_timer = 0;
	time_run = PNEUMATIC_DELAY;
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void CanGrab::Execute()
{

	time_timer = timer->Get();
	if(time_timer >= time_run)
	{
		wing_toggle = Robot::oi->getJoystick2()->GetRawButton(8);
		flopper_toggle = Robot::oi->getJoystick2()->GetRawButton(7);

		if(wing_toggle == true)
		{
			wing_open = !wing_open;
			if(wing_open == true)
			{
				Robot::canGrabber->wingSolenoid->Set(Robot::canGrabber->wingSolenoid->kForward);
			}
			else
			{
				Robot::canGrabber->wingSolenoid->Set(Robot::canGrabber->wingSolenoid->kReverse);
			}
		}
		if(flopper_toggle == true)
		{
			flopper_down = !flopper_down;
			if(flopper_down == true)
			{
				Robot::canGrabber->flopperSolenoid->Set(Robot::canGrabber->flopperSolenoid->kForward);
			}
			else
			{
				Robot::canGrabber->flopperSolenoid->Set(Robot::canGrabber->flopperSolenoid->kReverse);
			}
		}
		timer->Reset();
	}
	else
	{
		//cant to anything
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CanGrab::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CanGrab::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CanGrab::Interrupted()
{

}
