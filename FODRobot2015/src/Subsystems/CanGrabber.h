#ifndef CanGrabber_H
#define CanGrabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CanGrabber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CanGrabber();
	void InitDefaultCommand();
	DoubleSolenoid* flopperSolenoid;
	DoubleSolenoid* wingSolenoid;
};

#endif
