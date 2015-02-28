#ifndef LEDSUB_H
#define LEDSUB_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LEDSub: public Subsystem
{
private:
// It's desirable that everything possible under private except
// for methods that implement subsystem capabilities
public:
LEDSub();
void InitDefaultCommand();
DigitalOutput* Red_LED;
DigitalOutput* Green_LED;
DigitalOutput* Blue_LED;
};
#endif
