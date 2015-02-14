#include "LEDBright.h"
#include "LEDDim.h"
extern float LEDcounter;
LEDBright::LEDBright()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	isDone = false;
}

// Called just before this Command runs the first time
void LEDBright::Initialize()
{
	RobotMap::Red_LED->SetRaw(0);
	RobotMap::Green_LED->SetRaw(0);
	RobotMap::Blue_LED->SetRaw(0);
	isDone = false;

}

// Called repeatedly when this Command is scheduled to run
void LEDBright::Execute()
{
	if(LEDcounter != 2000)
	{
		RobotMap::Red_LED->SetRaw(LEDcounter + 100);
		RobotMap::Green_LED->SetRaw(LEDcounter + 100);
		RobotMap::Blue_LED->SetRaw(LEDcounter + 100);
	}
	isDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool LEDBright::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void LEDBright::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDBright::Interrupted()
{

}
