#ifndef WinchAuto_H
#define WinchAuto_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class WinchAuto: public Command
{
public:
	WinchAuto(double speed_param, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* timer;
	double speed;
	double time_run;
	double time_timer;
	bool isDoneWinchAuto;
};

#endif
