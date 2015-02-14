#ifndef LEDChanger_H
#define LEDChanger_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LEDChanger: public Command
{
public:
	LEDChanger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool dim_button;
	bool bright_button;
	float counter;
};

#endif
