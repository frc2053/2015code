#ifndef DoNothingAuto_H
#define DoNothingAuto_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

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
	double time_timer;
	bool NothingDone;
};

#endif
