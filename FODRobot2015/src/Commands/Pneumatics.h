#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Pneumatics: public Command
{
public:
	Pneumatics();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	bool left_Bumper = false;
	bool right_Bumper = false;
};

#endif
