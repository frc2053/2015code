// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RotatetoAngle.h"

RotatetoAngle::RotatetoAngle(float Angle, float Speed) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveBaseSub);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	SetInitAngle = Angle;
	SetAngleScaled = 0;
	MaxScalingSpeed = Speed;
	SetAngle = 0;
	SetSpeed = 0;
	IMU_Scaled = 0;
	IMU_Yaw = 0;
	ANGLE_TOLERANCE = 2;
	DRIVE_ANGLE = 0;
	DRIVE_X = 0;
	DRIVE_Y = 0;
	ROTATE_LOOP_CHECK = 5;
	TooFarCW = false;
    TooFarCCW = false;
    TimesThroughLoop = 0;
    RotCmd = 0;
    DegreesToSetPointAbs = 0;
    DegreesToSetPoint = 0;
    DriverRotateAxisOverride = 0;
    SpinDirection = 0;
    AutoRotDone = false;
}

// Called just before this Command runs the first time
void RotatetoAngle::Initialize() {
	AutoRotDone = false; // Just started - can't be done yet

	SetSpeed = 0; // Current spin speed for piece wise linear angle from set point distance
	MaxScalingSpeed = 1; // Scales SetSpeed by overall scaling factor (used to slow down whole spin)

	SetAngle = 0; // Saves the commanded go-to angle functional parameter passed in.
	SetInitAngle = 0; // Initial Set Angle for Rotation

	DriverRotateAxisOverride = 0; //Driver override AutoRotation value
	
	IMU_Yaw = 0;  //Yaw value from IMU and scaled value to eliminate
	IMU_Scaled = 0; // Translated to a non-wrapping scale (-180 to 180 -> 820 to 1180)
	SetAngleScaled = 0; // Converted value of the Commanded Set Angle to linear scale.

	SpinDirection = 1;  // Sets pin direction: 1=Clockwise from robot top, -1=CCW
	RotCmd = 0; //Calculated rotation speed to command

	//Assume we don't need the robot to spin until proven via measurement.
	TooFarCW = false; // Robot is further CW than set point: needs to spin CCW
	TooFarCCW = false; //Robot is further CCW than set point: needs to spin CW

	DegreesToSetPoint = 0; //Number of degrees from current angle to set point
	DegreesToSetPointAbs = 0; //absolute value of DegreesToSetPoint

	//Persistence of measurements of current angle to determine if system has stopped moving, overshooting
	TimesThroughLoop = 0;
}

// Called repeatedly when this Command is scheduled to run
void RotatetoAngle::Execute() {

	//printf("\nExecuting rotate to angle command");
	
	AutoRotDone = false; // Just started - can't be done yet

	DriverRotateAxisOverride = Robot::oi->getJoystick1()->GetRawAxis(4); //get joystick for override

	//Assume we don't need the robot to spin until proven via measurement.
	TooFarCW = false;
	TooFarCCW = false;

	//printf("\n");
	//printf("%f", SetSpeed);
	//printf("\n");

	//Default to no rotation commanded
	RotCmd = 0;

	//Read the actual Robot Angle from IMU
	IMU_Yaw = Robot::driveBaseSub->pRobot_IMU->GetYaw();

	//Scale the IMU reading
	IMU_Scaled = IMU_Yaw + 1000;
	//printf("(loop) Scaled IMU %3.2f\n", IMU_Scaled);

	//Scale Set Angle
	SetAngleScaled = SetAngle + 1000;
	//printf("(loop) Scaled Set Angle %3.2f\n", SetAngleScaled);

	//set spin direction and degrees to rotate to
	if(IMU_Scaled > (SetAngleScaled + ANGLE_TOLERANCE)) {
		TooFarCW = true;
		SpinDirection = -1;
		DegreesToSetPoint = IMU_Scaled - SetAngleScaled;
	}

	//set spin direction and degrees to rotate to
	if (IMU_Scaled < (SetAngleScaled - ANGLE_TOLERANCE)) {
		TooFarCCW = true;
		SpinDirection = 1;
		DegreesToSetPoint = SetAngleScaled - IMU_Scaled;
	}


	//Only start spinning if we need to.
	if (TooFarCW || TooFarCCW) {
		DegreesToSetPointAbs = fabs(DegreesToSetPoint);


		if(DegreesToSetPointAbs <= 180)
		{
			SetSpeed = 1;
		}
		if(DegreesToSetPointAbs < 90)
		{
			SetSpeed = 0.4;
		}
		if(DegreesToSetPointAbs < 60)
		{
			SetSpeed = 0.3;
		}
		if(DegreesToSetPointAbs < 30)
		{
			SetSpeed = 0.2;
		}

		// Convert from absolute angle back to direction based
		RotCmd = SpinDirection * SetSpeed;
		// Multiply in a master speed scaling factor that was passed in if needed
		RotCmd = RotCmd * MaxScalingSpeed;

		//We need to spin, so set counter to 1 - it shouldn't increment until it has previously spun then come to rest
		TimesThroughLoop = 1;

		//printf("\n(RotatetoAngle) SpinCW = %d     SpinCCW = %d     SpinDir = %d     RotCmd = %3.2f\n", TooFarCCW, TooFarCW, SpinDirection, RotCmd);

	}


	// If we didn't need to spin, we can end the command now.
	else {
		//printf("\n(loop)Didn't need to spin.\n\n");
		// either the robot has stabilized for so long after rotating or it never rotated to begin with
		if(TimesThroughLoop == ROTATE_LOOP_CHECK || TimesThroughLoop == 0)
		{
			AutoRotDone = true;
			// reset the loop counter now that the rotation is complete and stable
			TimesThroughLoop = 0;
			RotCmd = 0;
			//printf("\n(RotatetoAngle) Spinning Can Stop Now ");
		}

		//robot is within tolerance but hasn't yet been stable for the timeout
		TimesThroughLoop++;
		//printf("\ntimes through loop: %d", TimesThroughLoop);
	}


	//Auto Rotation
	if(DriverRotateAxisOverride > -0.20 && DriverRotateAxisOverride < 0.20)
	{
		Robot::driveBaseSub->MechDrive(DRIVE_X,DRIVE_Y,RotCmd,DRIVE_ANGLE);
		DriverRotateAxisOverride = 0;

	}
	//Driver rotation
	else
	{
		DriverRotateAxisOverride = DriverRotateAxisOverride * fabs(DriverRotateAxisOverride);
		Robot::driveBaseSub->MechDrive(DRIVE_X,DRIVE_Y,DriverRotateAxisOverride,DRIVE_ANGLE);
		TimesThroughLoop = 0;
		AutoRotDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RotatetoAngle::IsFinished() {
	//printf("\n\nRan through execute loop.\n\n");
	if(AutoRotDone == true)
	{
		//printf("AutoRotDone is true");
	}
	else
	{
		//printf("AutoRotDone is false");
	}
	return AutoRotDone;
}

// Called once after isFinished returns true
void RotatetoAngle::End() {
	//printf("\n In RotatetoAngle::End()");
	Robot::driveBaseSub->MechDrive(0,0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotatetoAngle::Interrupted() {
	//printf("\n In RotatetoAngle::Interrupted()");
	Robot::driveBaseSub->MechDrive(0,0,0,0);
}
