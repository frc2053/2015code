#include "DriveAuto.h"

DriveAuto::DriveAuto(double side, double fow, double rot, double yaw, double time) {
	Requires(Robot::driveBaseSub);
	
	isDoneDriveAuto = false;
	printf("\n In DriveAuto::DriveAuto");
	
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	timer = new Timer();
	
	time_timer = 0;
	isDoneDriveAuto = false;
	speed_side = side;
	speed_fow = fow;
	speed_rot = rot;
	imu_yaw = yaw;
	time_run = time;
	
	printf("\nDriveAuto ConstVals X=%3.2f  Y=%3.2f  Rot=%3.2f Yaw=%3.2f  Time=%3.2f", speed_side, speed_fow, speed_rot, imu_yaw, time_run);
}

// Called just before this Command runs the first time
void DriveAuto::Initialize() {
	printf("\n In DriveAuto::Initialize()");
	printf("\nDriveAuto InitVals X=%3.2f  Y=%3.2f  Rot=%3.2f Yaw=%3.2f  Time=%3.2f", speed_side, speed_fow, speed_rot, imu_yaw, time_run);
	
	timer->Reset();
	timer->Start();
	
	printf("\n Done timer->Start();");

	isDoneDriveAuto = false;
}

// Called repeatedly when this Command is scheduled to run
void DriveAuto::Execute() {
	printf("\n In DriveAuto::Execute()");
	
	time_timer = timer->Get();
	
	printf("\nDriveAuto ExeVals X=%3.2f  Y=%3.2f  Rot=%3.2f Yaw=%3.2f  Time=%3.2f", speed_side, speed_fow, speed_rot, imu_yaw, time_timer);

	
	Robot::driveBaseSub->MechDrive(speed_side, speed_fow, speed_rot, imu_yaw);
	
	if(time_timer >= time_run)
	{
		isDoneDriveAuto = true;
		printf("\nisDoneDriveAuto = true;");
	}
	else
	{
		isDoneDriveAuto = false;
		printf("\nisDoneDriveAuto = false;");
	}
	
	printf("\n Leaving DriveAuto::Execute()");
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveAuto::IsFinished() {

	if(isDoneDriveAuto == true)
	{
		printf("\n In DriveAuto::IsFinished(), returning isDoneDriveAuto= true ");
	}
	else
	{
		printf("\n In DriveAuto::IsFinished(), returning isDoneDriveAuto= false ");
	}
	return isDoneDriveAuto;
	
	printf("\n Done DriveAuto::IsFinished(),");

}

// Called once after isFinished returns true
void DriveAuto::End() {

	printf("\n In DriveAuto::End()");

	timer->Stop();
	printf("drive auto over.");
	
	printf("\n Done DriveAuto::End()");
	
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAuto::Interrupted() {

	printf("\n In DriveAuto::Interrupted()");
}
