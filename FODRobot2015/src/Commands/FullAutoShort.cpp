#include <Commands/PneumaticsAuto.h>
#include "FullAutoShort.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "RotatetoAngle.h"
#include "DriveWhileWinching.h"

FullAutoShort::FullAutoShort()
{
	//Grab first tote then move to the next one while raising the first
	AddSequential(new PneumaticsAuto(true,true, true));
	AddSequential(new DriveWhileWinching(0.0,-0.5,0.0,0.0,1.5,0.5,1));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop first tote on second tote, then pick up second tote
	AddParallel(new PneumaticsAuto(true,true, false));
	AddSequential(new WinchAuto(-0.5,1));
	AddSequential(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAuto(true,true, true));

	//move to final tote
	AddSequential(new DriveWhileWinching(0.0,-0.5,0.0,0.0,1.5,0.5,1));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop first and second totes(ma-goats) on final tote, then grab final tote
	AddSequential(new PneumaticsAuto(true,true, false));
	AddSequential(new WinchAuto(-0.5,1));
	AddSequential(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAuto(true,true, true));

	//lift all totes(ma-goats) slightly while also moving into auto zone
	//AddParallel(new RotatetoAngle(90,1));
	//AddSequential(new driveAuto(0.0,0.5,0.0,0.0,2);
	AddSequential(new DriveWhileWinching(1.0,0.0,0.0,0.0,2,0.5,0.25));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop totes and back away
	AddParallel(new WinchAuto(-0.5,0.25));
	AddSequential(new PneumaticsAuto(true,true, false));
	AddSequential(new DriveWhileWinching(0.0,0.4,0.0,0.0,0.25,0.0,0.0));
	AddParallel(new driveAuto(0.0,0.0,0.0,0.0,0.0));
}
