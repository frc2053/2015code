/*
 * TigerDriveBase.h
 *
 *  Created on: Apr 11, 2015
 *      Author: Drew Williams & Walter Keyes
 */

#ifndef SRC_TIGERDRIVE_TIGERDRIVEBASE_H_
#define SRC_TIGERDRIVE_TIGERDRIVEBASE_H_

#include <Math.h>

class TigerDriveBase
{
public:
	TigerDriveBase();
	static float GetAdjYaw(float raw_IMU);
	static float IMU_YAWoffset(float offset);
	static float GetRotateCommand(float Speed, float IMU_Raw);
	static void SetAngleFunction(float angle);
	float SetSpeed; // Current spin speed for piece wise linear angle from set point distance
	float SetAngle; // Saves the commanded go-to angle functional parameter passed in.
	float SetInitAngle; // Initial Set Angle for Rotation
	float MaxScalingSpeed; // Scales SetSpeed by overall scaling factor (used to slow down whole spin)
	float AutoRotCmd; // Rotate command from AutoRotate calculator
private:
	static const float ROTATE_LOOP_CHECK = 5; //checks for iterations through loop. Change later depending on robot
	static float IMU_Yaw;  //Yaw value from IMU and scaled value to eliminate
	static float IMU_Scaled; // Translated to a non-wrapping scale (-180 to 180 -> 820 to 1180)
	static float SetAngleScaled; // Converted value of the Commanded Set Angle to linear scale.
	static int SpinDirection;  // Sets pin direction: 1=Clockwise from robot top, -1=CCW
	static float RotCmd; //Calculated rotation speed to command

	//Assume we don't need the robot to spin until proven via measurement.
	static bool TooFarCW; // Robot is further CW than set point: needs to spin CCW
	static bool TooFarCCW; //Robot is further CCW than set point: needs to spin CW
	static float DegreesToSetPoint; //Number of degrees from current angle to set point
	static float DegreesToSetPointAbs; //absolute value of DegreesToSetPoint
	//Persistence of measurements of current angle to determine if system has stopped moving, overshooting
	static int TimesThroughLoop;
	static bool AutoRotDone; //Rotate command is done
	static float calculatedoffset; //calculated for imu offset
	static float yawoffset; //calc param
protected:
	static const float ANGLE_TOLERANCE = 2; // Tolerance in degrees on either side of set angle
};
#endif
