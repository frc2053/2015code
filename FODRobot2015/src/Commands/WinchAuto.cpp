#include "WinchAuto.h"

WinchAuto::WinchAuto(double speed_param, double time)
{
	Requires(Robot::winch);
	timer = new Timer();
	isDoneWinchAuto = false;
	time_timer = 0;
	time_run = time;
	speed = speed_param;
}

// Called just before this Command runs the first time
void WinchAuto::Initialize()
{
	timer->Reset();
	timer->Start();
	isDoneWinchAuto = false;
}

// Called repeatedly when this Command is scheduled to run
void WinchAuto::Execute()
{
	time_timer = timer->Get();
	Robot::winch->WinchMotor(speed);
	if(time_timer >= time_run)
	{
		Robot::winch->WinchMotor(0);
		isDoneWinchAuto = true;
	}
	else
	{
		isDoneWinchAuto = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WinchAuto::IsFinished()
{
	return isDoneWinchAuto;
}

// Called once after isFinished returns true
void WinchAuto::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchAuto::Interrupted()
{

}
