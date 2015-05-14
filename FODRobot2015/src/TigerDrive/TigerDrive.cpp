#include "TigerDrive.h"

TigerDrive::TigerDrive(float tolerance, IMU imuP)
{
	imuPointer = imuP;
	imuYaw = 0;
	angleTolerance = tolerance;
	rotateLoopCheck = 5;
	originalAngle = 0;
	speedWhileRotating = 0;
	speedScaleFactor = 1;
	imuRaw = 0;
	imuScaled = 0;
	scaledAngle = 0;
	spinDirection = 0;
	calculatedRotate = 0;
	tooFarCW = false;
	tooFarCCW = false;
	degreesToAngle = 0;
	degreesToAngleAbs = 0;
	timesThroughLoop = 0;
	isRotDone = false;
	yawOffset = 0;
	calculatedOffset = 0;
}

float TigerDrive::RotateToAngleDrive(float angle, float speed)
{
	setIsDone(false);
	setOriginalAngle(angle);
	setSpeedScaleFactor(speed);
	setTooFarCW(false);
	setTooFarCCW(false);
	setCalculatedRotate(0);
	setImuYaw(getAdjYaw());
	setImuScaled(getImuYaw());
	setScaledAngle(ScaleAngle(getOriginalAngle()));
	//sets spin direction and degrees to rotate to
	if(getImuScaled() > (getScaledAngle() + getAngleTolerance()))
	{
		setTooFarCW(true);
		setSpinDirection(-1);
		setDegreesToAngle(getImuScaled() - getScaledAngle());
	}
	//sets spin direction and degrees to rotate to
	if(getImuScaled() < (getScaledAngle() - getAngleTolerance()))
	{
		setTooFarCCW(true);
		setSpinDirection(1);
		setDegreesToAngle(getScaledAngle() - getImuScaled());
	}
	//only start spinning if we need to
	if(getTooFarCW() || getTooFarCCW())
	{
		setDegreesToAngleABS(fabs(getDegreesToAngle()));
		//why not an exponetial function? :(
		if(getDegreesToAngleABS() <= 180)
		{
			setSpeedWhileRotating(1);
		}
		if(getDegreesToAngleABS() <= 90)
		{
			setSpeedWhileRotating(0.4);
		}
		if(getDegreesToAngleABS() <= 60)
		{
			setSpeedWhileRotating(0.3);
		}
		if(getDegreesToAngleABS() <= 30)
		{
			setSpeedWhileRotating(0.2);
		}
		setCalculatedRotate(getSpinDirection() * getSpeedWhileRotating());
		setCalculatedRotate(getCalculatedRotate() * getSpeedScaleFactor());
		setTimesThroughLoop(1);
	}
	else
	{
		if(getTimesThroughLoop() == getRotateLoopCheck() || getTimesThroughLoop() == 0)
		{
			setIsDone(true);
			setTimesThroughLoop(0);
			setCalculatedRotate(0);
		}
		setTimesThroughLoop(getTimesThroughLoop() + 1);
	}
	return calculatedRotate;
}

float TigerDrive::ScaleAngle(float angleOriginal)
{
	return getOriginalAngle + 1000;
}

float TigerDrive::getAngleTolerance()
{
	return angleTolerance;
}

void TigerDrive::setAngleTolerance(float tolerance)
{
	angleTolerance = tolerance;
}

int TigerDrive::getRotateLoopCheck()
{
	return rotateLoopCheck;
}

void TigerDrive::setRotateLoopCheck(int loopCheck)
{
	rotateLoopCheck = loopCheck;
}

float TigerDrive::getOriginalAngle()
{
	return originalAngle;
}

void TigerDrive::setOriginalAngle(float angle)
{
	originalAngle = angle;
}

float TigerDrive::getSpeedWhileRotating()
{
	return speedWhileRotating;
}

void TigerDrive::setSpeedWhileRotating(float currentSpeed)
{
	speedWhileRotating = currentSpeed;
}

float TigerDrive::getSpeedScaleFactor()
{
	return speedScaleFactor;
}

void TigerDrive::setSpeedScaleFactor(float scaleFactor)
{
	speedScaleFactor = scaleFactor;
}

float TigerDrive::getImuScaled()
{
	return imuScaled;
}

void TigerDrive::setImuScaled(float scaledImu)
{
	imuScaled = scaledImu;
}

float TigerDrive::getScaledAngle()
{
	return scaledAngle;
}

void TigerDrive::setScaledAngle(float angleScaled)
{
	scaledAngle = angleScaled;
}

int TigerDrive::getSpinDirection()
{
	return spinDirection;
}

void TigerDrive::setSpinDirection(int spinDir)
{
	spinDirection = spinDir;
}

float TigerDrive::getCalculatedRotate()
{
	return calculatedRotate;
}

void TigerDrive::setCalculatedRotate(float calcRot)
{
	calculatedRotate = calcRot;
}

bool TigerDrive::getTooFarCW()
{
	return tooFarCW;
}

void TigerDrive::setTooFarCW(bool CW)
{
	tooFarCW = CW;
}

bool TigerDrive::getTooFarCCW()
{
	return tooFarCCW;
}

void TigerDrive::setTooFarCCW(bool CCW)
{
	tooFarCCW = CCW;
}

float TigerDrive::getDegreesToAngle()
{
	return degreesToAngle;
}

void TigerDrive::setDegreesToAngle(float degreesAngle)
{
	degreesToAngle = degreesAngle;
}

float TigerDrive::getDegreesToAngleABS()
{
	return degreesToAngleAbs;
}

void TigerDrive::setDegreesToAngleABS(float degreesAngleABS)
{
	degreesToAngleAbs = degreesAngleABS;
}

float TigerDrive::getTimesThroughLoop()
{
	return timesThroughLoop;
}

void TigerDrive::setTimesThroughLoop(int timeLoop)
{
	timesThroughLoop = timeLoop;
}

bool TigerDrive::getIsDone()
{
	return isRotDone;
}

void TigerDrive::setIsDone(bool isDone)
{
	isRotDone = isDone;
}

float TigerDrive::getAdjYaw()
{
	setImuRaw(imuPointer->GetYaw());
	setCalcOffset(getImuRaw() + getOffset());
	if(getCalcOffset() >= 180)
	{
		setCalcOffset(getCalcOffset() - 360);
	}
	return getCalcOffset();
}

float TigerDrive::getCalcOffset()
{
	return calculatedOffset;
}

void TigerDrive::setCalcOffset(float calcOffSet)
{
	calculatedOffset = calcOffSet;
}

float TigerDrive::getOffset()
{
	return yawOffset;
}

void TigerDrive::setOffset(float offset)
{
	yawOffset = offset;
}

float TigerDrive::getImuRaw()
{
	return imuRaw;
}

void TigerDrive::setImuRaw(float raw)
{
	imuRaw = raw;
}

float TigerDrive::getImuYaw()
{
	return imuYaw;
}

void TigerDrive::setImuYaw(float yaw)
{
	imuYaw = yaw;
}
