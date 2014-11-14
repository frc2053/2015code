#ifndef ZEROYAW_H
#define ZEROYAW_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Proggrammer
 */
class ZeroYaw: public Command {
public:
	ZeroYaw();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
