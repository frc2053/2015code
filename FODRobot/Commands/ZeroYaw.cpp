#include "ZeroYaw.h"

ZeroYaw::ZeroYaw() {
	// Use requires() here to declare subsystem dependencies
	Requires(Robot::driveBaseSub);
}

// Called just before this Command runs the first time
void ZeroYaw::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ZeroYaw::Execute() {
	do {
		Robot::driveBaseSub->pRobot_IMU->ZeroYaw();
	}
	while(1 == 0);
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroYaw::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ZeroYaw::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroYaw::Interrupted() {
}
