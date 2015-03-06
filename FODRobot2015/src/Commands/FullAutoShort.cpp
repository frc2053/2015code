#include <Commands/PneumaticsAuto.h>
#include "FullAutoShort.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "RotatetoAngle.h"
#include "DriveWhileWinching.h"
#include "Commands/SetOffSet.h"

FullAutoShort::FullAutoShort()
{
	AddSequential(new SetOffSet(-90));
	//Grab first tote then move to the next one while raising the first
	//AddSequential(new PneumaticsAuto(true,true, false));
	AddSequential(new PneumaticsAuto(true, false, false));
	AddSequential(new PneumaticsAuto(false, true, false));
	AddSequential(new WinchAuto(1, .4));
	AddSequential(new DriveWhileWinching(0.0,-0.5,0.0,0.0,1.4,1,1));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop first tote on second tote, then pick up second tote
	AddSequential(new WinchAuto(-1,0.5));
	AddSequential(new PneumaticsAuto(true,true, true));
	AddSequential(new WinchAuto(-0.5,1));
	AddSequential(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAuto(true,true, false));

	//winches up to final tote
	AddSequential(new WinchAuto(1, .8));
	AddSequential(new DriveWhileWinching(0.0,-0.5,0.0,0.0,1.5,1,1));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop first and second totes(ma-goats) on final tote, then grab final tote
	AddSequential(new WinchAuto(-1,0.5));
	AddSequential(new PneumaticsAuto(true,true, true));
	AddSequential(new WinchAuto(-0.5,1.3));
	AddSequential(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAuto(true,true, false));

	//lift all totes(ma-goats) slightly while also moving into auto zone
	AddSequential(new WinchAuto(1,0.5));
	AddSequential(new driveAuto(0.75,0.0,0.0,0.0,2));
	AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//drop totes and back away
	AddSequential(new WinchAuto(-0.5,0.25));
	AddSequential(new PneumaticsAuto(true,true, true));
	AddSequential(new DriveWhileWinching(0.0,0.4,0.0,0.0,0.25,0.0,0.0));
	AddSequential(new driveAuto(0.0,0.0,0.0,0.0,0.0));
}
