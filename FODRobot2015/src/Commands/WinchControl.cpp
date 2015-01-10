#include "WinchControl.h"

WinchControl::WinchControl()
{
	Requires(Robot::winch);
	winchUp = 0;
	winchDown = 0;
	winchSpeed = 0;
}

// Called just before this Command runs the first time
void WinchControl::Initialize()
{
	winchUp = 0;
	winchDown = 0;
	winchSpeed = 0;
}

// Called repeatedly when this Command is scheduled to run
void WinchControl::Execute()
{
	//gets joystick values
	winchUp = fabs(Robot::oi->getJoystick2()->GetRawAxis(3));
	winchDown = fabs(Robot::oi->getJoystick2()->GetRawAxis(2));

	//dead bands
	if(winchUp < 0.20)
	{
		winchUp = 0;
	}
	else
	{
		winchUp = winchUp * fabs(winchUp);
	}



	if(winchDown < 0.20)
	{
		winchDown = 0;
	}
	else
	{
		winchDown = winchDown * fabs(winchDown);
	}

	if(winchUp != 0 && winchDown != 0)
	{
		if(winchUp > winchDown)
		{
			winchSpeed = winchUp;
		}
		else
		{
			winchSpeed = winchDown;
		}
	}
	SmartDashboard::PutNumber("WinchUp", winchUp);
	SmartDashboard::PutNumber("WinchDown", winchDown);
	Robot::winch->WinchMotor(winchSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool WinchControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WinchControl::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchControl::Interrupted()
{

}
