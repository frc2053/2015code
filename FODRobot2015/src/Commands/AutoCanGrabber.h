#ifndef AutoCanGrabber_H
#define AutoCanGrabber_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoCanGrabber: public Command
{
public:
	AutoCanGrabber(bool wings, bool flopper, bool open_close);
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
	double const PNEUMATIC_DELAY = 0.1;
	bool wingopen;
	bool flopperdown;
	bool open_close;
};

#endif
