#ifndef Winch_H
#define Winch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Winch();
	void InitDefaultCommand();
	void WinchMotor(float);
	CANJaguar* winchTalon;
	DigitalInput* bottomSwitch;
};

#endif
