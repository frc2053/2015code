#ifndef DoNothingAuto_H
#define DoNothingAuto_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class DoNothingAuto: public Command
{
public:
	DoNothingAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* timer;
	double time_run;
	float time_timer;
	bool NothingDone;
};

#endif
