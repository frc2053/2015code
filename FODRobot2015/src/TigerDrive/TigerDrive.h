#ifndef SRC_TIGERDRIVE_TIGERDRIVE_H_
#define SRC_TIGERDRIVE_TIGERDRIVE_H_

class TigerDrive
{
private:
	IMU* imuPointer;
	float angleTolerance; // Tolerance in degrees on either side of set angle
	int rotateLoopCheck; //checks for iterations through loop. Change later depending on robot
	float originalAngle; // was SetInitAngle (set to variable passed in)
	float speedWhileRotating; // Current spin speed for piece wise linear angle from set point distance
	float speedScaleFactor; //was MaxScalingSpeed scales speed for slower rotation
	float imuRaw; //Raw imu reading
	float imuYaw;
	float imuScaled; // Was IMU_Scaled Translated to a non-wrapping scale (-180 to 180 -> 820 to 1180)
	float scaledAngle; //was SetAngleScaled converts angle to linear scale
	int spinDirection;  // Was SpinDirection Sets pin direction: 1=Clockwise from robot top, -1=CCW
	float calculatedRotate; //Calculated rotation speed to mecDrive
	//Assume we don't need the robot to spin until proven via measurement.
	bool tooFarCW; // Robot is further CW than set point: needs to spin CCW
	bool tooFarCCW; //Robot is further CCW than set point: needs to spin CW
	float degreesToAngle; //Number of degrees from current angle to set point
	float degreesToAngleAbs; //absolute value of DegreesToSetPoint
	//Persistence of measurements of current angle to determine if system has stopped moving, overshooting
	int timesThroughLoop;
	bool isRotDone; //Was AutoRotDone Rotate command is done
	float calculatedOffset; //used for auto modes
	float yawOffset; //passed in
public:
	TigerDrive(float tolerance, IMU imuYaw);
	float RotateToAngleDrive(float angle, float speed);
	float ScaleAngle(float angleOriginal);
	float getAngleTolerance();
	void setAngleTolerance(float tolerance);
	int getRotateLoopCheck();
	void setRotateLoopCheck(int loopCheck);
	float getOriginalAngle();
	void setOriginalAngle(float angle);
	float getSpeedWhileRotating();
	void setSpeedWhileRotating(float currentSpeed);
	float getSpeedScaleFactor();
	void setSpeedScaleFactor(float scaleFactor);
	float getImuScaled();
	void setImuScaled(float scaledImu);
	float getScaledAngle();
	void setScaledAngle(float angleScaled);
	int getSpinDirection();
	void setSpinDirection(int spinDir);
	float getCalculatedRotate();
	void setCalculatedRotate(float calcRot);
	bool getTooFarCW();
	void setTooFarCW(bool CW);
    bool getTooFarCCW();
	void setTooFarCCW(bool CCW);
	float getDegreesToAngle();
	void setDegreesToAngle(float degreesAngle);
	float getDegreesToAngleABS();
	void setDegreesToAngleABS(float degreesAngleABS);
	float getTimesThroughLoop();
	void setTimesThroughLoop(int timeLoop);
	bool getIsDone();
	void setIsDone(bool isDone);
	float getAdjYaw();
	void setOffset(float offset);
	float getOffset();
	void setCalcOffset(float calcOffSet);
	float getCalcOffset();
	float getImuRaw();
	void setImuRaw(float raw);
	float getImuYaw();
	void setImuYaw(float yaw);
};
#endif /* SRC_TIGERDRIVE_TIGERDRIVE_H_ */
