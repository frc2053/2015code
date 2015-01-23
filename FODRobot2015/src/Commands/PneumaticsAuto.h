#ifndef PneumaticsAuto_H
#define PneumaticsAuto_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class PneumaticsAuto: public Command
{
public:
	PneumaticsAuto(bool left, bool right, bool oc);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* timer;
	double time_run;
	double time_timer;
	bool PneumaticsDone;
	double const PNEUMATIC_DELAY = 1;
	bool leftArm;
	bool rightArm;
	bool open_close;
};

#endif
