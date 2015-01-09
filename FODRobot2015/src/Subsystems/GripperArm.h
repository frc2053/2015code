#ifndef GripperArm_H
#define GripperArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class GripperArm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	GripperArm();
	void InitDefaultCommand();
	DoubleSolenoid* leftGripper;
	DoubleSolenoid* rightGripper;
};

#endif
