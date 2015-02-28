#include "LEDSub.h"
#include "../RobotMap.h"
#include "../Commands/LEDCmd.h"

LEDSub::LEDSub() :
Subsystem("LED Subsystem")
{
	Red_LED = RobotMap::Red_LED;
	Blue_LED = RobotMap::Blue_LED;
	Green_LED = RobotMap::Green_LED;
}
void LEDSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LEDCmd());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
