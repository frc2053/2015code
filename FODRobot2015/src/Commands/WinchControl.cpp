#include "WinchControl.h"

WinchControl::WinchControl()
{
	//printf("winchControl const\n");
	Requires(Robot::winch);
	winchUp = 0;
	winchDown = 0;
	winchSpeed = 0;
	isClosed = false;
}

// Called just before this Command runs the first time
void WinchControl::Initialize()
{
	//printf("winchControl init\n");
	winchUp = 0;
	winchDown = 0;
	winchSpeed = 0;
	isClosed = false;
}

// Called repeatedly when this Command is scheduled to run
void WinchControl::Execute()
{
	isClosed = RobotMap::bottomSwitch->Get();
	//printf("isClosed = %d", isClosed);
	//printf("winchControl execute\n");
	//gets joystick values
	winchUp = fabs(Robot::oi->getJoystick2()->GetRawAxis(3));
	winchDown = fabs((Robot::oi->getJoystick2()->GetRawAxis(2)) / 2);

		if(winchUp > winchDown)
		{
			winchSpeed = winchUp;
		}
		else
		{
			winchSpeed = -winchDown;
		}


	//SmartDashboard::PutNumber("WinchUp", winchUp);
	//SmartDashboard::PutNumber("WinchDown", winchDown);

	if(isClosed == false)
	{
		Robot::winch->WinchMotor(0);
	}
	else
	{
		Robot::winch->WinchMotor(winchSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WinchControl::IsFinished()
{
	//printf("winchControl isFinished\n");
	return false;
}

// Called once after isFinished returns true
void WinchControl::End()
{
	//printf("winchControl end\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchControl::Interrupted()
{
	//printf("winchControl interrupted\n");
}
