#include "LEDChanger.h"

LEDChanger::LEDChanger()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	dim_button = false;
	bright_button = false;
	counter = 0;
}

// Called just before this Command runs the first time
void LEDChanger::Initialize()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	dim_button = false;
	bright_button = false;
	counter = 0;

}

// Called repeatedly when this Command is scheduled to run
void LEDChanger::Execute()
{
	dim_button = Robot::oi->getJoystick1()->GetRawButton(7);
	bright_button = Robot::oi->getJoystick1()->GetRawButton(8);

	if(counter != 0 && counter != 2000)
	{
		if(dim_button == true)
		{
			RobotMap::Red_LED->SetRaw(counter - 100);
			RobotMap::Green_LED->SetRaw(counter - 100);
			RobotMap::Blue_LED->SetRaw(counter - 100);
		}

		if(bright_button == true)
		{
			RobotMap::Red_LED->SetRaw(counter - 100);
			RobotMap::Green_LED->SetRaw(counter - 100);
			RobotMap::Blue_LED->SetRaw(counter - 100);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LEDChanger::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LEDChanger::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDChanger::Interrupted()
{

}
