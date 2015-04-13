/*
 * TigerDriveBase.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: Drew Williams & Walter Keyes
 */

#include "TigerDriveBase.h"

TigerDriveBase::TigerDriveBase()
{
	SetSpeed = 0; // Current spin speed for piece wise linear angle from set point distance
	MaxScalingSpeed = 1; // Scales SetSpeed by overall scaling factor (used to slow down whole spin)

	SetAngle = 0; // Saves the commanded go-to angle functional parameter passed in.
	SetInitAngle = 0; // Initial Set Angle for Rotation

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

	AutoRotCmd = 0; // Rotate command from AutoRotate calculator

	AutoRotDone = true; //Rotate command is done
	calculatedoffset = 0;
	yawoffset = 0;
}

float TigerDriveBase::IMU_YAWoffset(float offset)
{
	yawoffset = offset;
	return yawoffset;
}

float TigerDriveBase::GetAdjYaw(float raw_IMU)
{
	IMU_Yaw = raw_IMU;
	calculatedoffset = IMU_Yaw + yawoffset;
	if(calculatedoffset >= 180)
	{
		calculatedoffset = calculatedoffset - 360;
	}
	return calculatedoffset;
}

float TigerDriveBase::GetRotateCommand(float Speed, float IMU_Raw)
{
	AutoRotCmd = 0;
	AutoRotDone = false; // Just started - can't be done yet

	//passes in values
	SetInitAngle = TigerDriveBase::GetAngleFunction();
	MaxScalingSpeed = Speed;

	//Assume we don't need the robot to spin until proven via measurement.
	TooFarCW = false;
	TooFarCCW = false;

	//Default to no rotation commanded
	RotCmd = 0;

	//Read the actual Robot Angle from IMU
	IMU_Yaw = TigerDriveBase::GetAdjYaw(IMU_Raw);

	//Scale the IMU reading
	IMU_Scaled = IMU_Yaw + 1000;

	//Scale Set Angle
	SetAngleScaled = SetInitAngle + 1000;
	//printf("\n(DriveRotateLoop) Scaled IMU %3.2f  Scaled Set Angle %3.2f\n", IMU_Scaled, SetAngleScaled);

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

		//scale speeds based on degrees. Why not an exponential function? :(
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

		//printf("\n(DriveRotateLoop) SpinCW = %d     SpinCCW = %d     SpinDir = %d     RotCmd = %3.2f\n", TooFarCCW, TooFarCW, SpinDirection, RotCmd);

	}


	// If we didn't need to spin, we can end the command now.
	else {
		//printf("\n(DriveRotateLoop) Didn't need to spin.");
		// either the robot has stabilized for so long after rotating or it never rotated to begin with
		if(TimesThroughLoop == ROTATE_LOOP_CHECK || TimesThroughLoop == 0)
		{
			AutoRotDone = true;
			// reset the loop counter now that the rotation is complete and stable
			TimesThroughLoop = 0;
			RotCmd = 0;
			//printf("\n(DriveRotateLoop) Spinning Can Stop Now ");
		}

		//robot is within tolerance but hasn't yet been stable for the timeout
		TimesThroughLoop++;

	}

	//printf("\n Leaving driveCommand::RotateToAngleDrive");
	return RotCmd;
}

void TigerDriveBase::SetAngleFunction(int angle)
{
	SetAngle = angle;
}

float TigerDriveBase::GetAngleFunction()
{
	return SetAngle;
}
