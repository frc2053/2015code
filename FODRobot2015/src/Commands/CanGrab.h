#ifndef CanGrab_H
#define CanGrab_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class CanGrab: public Command
{
public:
	CanGrab();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	bool wing_toggle = false;
	bool flopper_toggle = false;
	bool wing_open = false;
	bool flopper_down = false;

};

#endif
