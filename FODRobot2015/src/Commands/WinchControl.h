#ifndef WinchControl_H
#define WinchControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class WinchControl: public Command	{
public:
	WinchControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float winchUp;		//used to set speed if winch is going up
	float winchDown;	//used to set speed if winch is going down
	float winchSpeed;	//sets the speed at which the winch turns
};

#endif
