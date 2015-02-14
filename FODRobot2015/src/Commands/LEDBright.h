#ifndef LEDBright_H
#define LEDBright_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LEDBright: public Command
{
public:
	LEDBright();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool isDone;
};

#endif
