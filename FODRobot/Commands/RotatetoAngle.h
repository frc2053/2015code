#ifndef ROTATETOANGLE_H
#define ROTATETOANGLE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class RotatetoAngle: public Command {
public:
	RotatetoAngle(float Angle, float Speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	int ANGLE_TOLERANCE_ALONE; // Tolerance in degrees on either side of set angle
	int DRIVE_ANGLE_ALONE; // Only causing drive spins in this command - it doesn't need to know angle.  
	int DRIVE_X_ALONE; // used for translation magnitude to drive command - not used - stays 0
	int DRIVE_Y_ALONE; // used for translation magnitude to drive command - not used - stays 0
	int LOOP_IT_CHECK_ALONE; //checks for iterations through loop. Change later depending on robot


	float imu_yaw_Alone; // Measurement from the IMU
	float IMU_Scaled_Alone; // Translated to a non-wrapping scale (-180 to 180 -> 820 to 1180)

	float RotateAxisOverride_Alone; //Joystick value

	float setSpeed_Alone; // Saves the rotation speed functional parameter passed in.
	float setAngle_Alone; // Saves the commanded go-to angle functional parameter passed in.

	float setinitSpeed_Alone; // Initial Set Speed
	float setinitAngle_Alone; // Initial Set Angle

	float degrees_to_Alone; //degrees to rotate to "Rotato" - Walter 2014
	float degrees_to_abs_Alone; //absolute value of degrees_to
	float setAngleScaled_Alone; // Converted value of the Commanded Set Angle to linear scale.
	float spinDirection_Alone;  // Sets pin direction: 1=Clockwise from robot top, -1=CCW

	float RotCmd_Alone; // Direction * Rot Speed passed to drive command.

	bool TooFarCW_Alone; // Robot is further CW than set point: needs to spin CCW
	bool TooFarCCW_Alone; //Robot is further CCW than set point: needs to spin CW

	bool TooFarCCWDupe_Alone;
	bool TooFarCWDupe_Alone; //Basically duplicates of variables above

	bool isDone_Alone; //Flag to OS/WPI to end this command.

	int times_through_loop_Alone; //counter for fixing overshooting
};

#endif
