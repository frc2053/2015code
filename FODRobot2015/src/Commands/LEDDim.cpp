#include "LEDDim.h"
float LEDcounter = 0;
LEDDim::LEDDim()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	isDone = false;
}

// Called just before this Command runs the first time
void LEDDim::Initialize()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	isDone = false;

}

// Called repeatedly when this Command is scheduled to run
void LEDDim::Execute()
{
	if(LEDcounter != 0)
	{
		RobotMap::Red_LED->SetRaw(LEDcounter - 100);
		RobotMap::Green_LED->SetRaw(LEDcounter - 100);
		RobotMap::Blue_LED->SetRaw(LEDcounter - 100);
	}
	isDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool LEDDim::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void LEDDim::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDDim::Interrupted()
{

}
