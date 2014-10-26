#ifndef ROTATETOANGLE_H
#define ROTATETOANGLE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class RotatetoAngle: public Command {
public:
	RotatetoAngle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

