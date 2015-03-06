#include "SetOffSet.h"

SetOffSet::SetOffSet(float input)
{
	Requires(Robot::driveBaseSub);
	isDone = false;
	inputYaw = input;
}

// Called just before this Command runs the first time
void SetOffSet::Initialize()
{
	isDone = false;
}

// Called repeatedly when this Command is scheduled to run
void SetOffSet::Execute()
{
	Robot::driveBaseSub->IMU_YAWoffset(inputYaw);
	isDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool SetOffSet::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void SetOffSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetOffSet::Interrupted()
{

}
