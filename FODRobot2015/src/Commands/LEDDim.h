#ifndef LEDDim_H
#define LEDDim_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LEDDim: public Command
{
public:
	LEDDim();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool isDone;
};

#endif
