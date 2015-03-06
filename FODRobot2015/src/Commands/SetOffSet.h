#ifndef SetOffSet_H
#define SetOffSet_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SetOffSet: public Command
{
public:
	SetOffSet(float input);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	bool isDone;
	float inputYaw;
};

#endif
