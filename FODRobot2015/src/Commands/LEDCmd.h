#ifndef LEDCMD_H
#define LEDCMD_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LEDCmd: public Command
{
public:
	LEDCmd();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
