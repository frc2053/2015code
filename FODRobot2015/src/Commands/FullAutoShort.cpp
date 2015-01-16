#include "FullAutoShort.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAutoClose.h"
#include "PneumaticsAutoOpen.h"
#include "RotatetoAngle.h"

FullAutoShort::FullAutoShort()
{
	//Grab first tote then move to the next one while raising the first
	AddSequential(new PneumaticsAutoClose(true,true));
	AddParallel(new driveAuto(0.0,-0.5,0.0,0.0,1.5));
	AddSequential(new WinchAuto(0.5,1));
	AddParallel(new driveAuto(0.0,0.0,0.0,0.0,0.0));
	AddSequential(new WinchAuto(0.0,0));

	//drop first tote on second tote, then pick up second tote
	AddParallel(new PneumaticsAutoOpen(true,true));
	AddSequential(new WinchAuto(-0.5,1));
	AddParallel(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAutoClose(true,true));
	printf("Done");

	//move to final tote
	/*AddParallel(new driveAuto(0.0,-0.5,0.0,0.0,1.5));
	AddSequential(new WinchAuto(0.5,1));
	AddParallel(new driveAuto(0.0,0.0,0.0,0.0,0.0));
	AddParallel(new WinchAuto(0.0,0));

	//drop first and second totes(ma-goats) on final tote, then grab final tote
	AddSequential(new PneumaticsAutoOpen(true,true));
	AddSequential(new WinchAuto(-0.5,1));
	AddParallel(new WinchAuto(0.0,0));
	AddSequential(new PneumaticsAutoClose(true,true));

	//lift all totes(ma-goats) slightly while also moving into auto zone
	AddParallel(new WinchAuto(0.5,0.25));
	AddParallel(new RotatetoAngle(90,1));
	AddSequential(new driveAuto(1.0,0.0,0.0,0.0,2));
	AddParallel(new driveAuto(0.0,0.0,0.0,0.0,0.0));
	AddSequential(new WinchAuto(0.0,0));

	//drop totes and back away
	AddParallel(new WinchAuto(-0.5,0.25));
	AddSequential(new PneumaticsAutoOpen(true,true));
	AddParallel(new WinchAuto(0.0,0));
	AddSequential(new driveAuto(0.0,0.4,0.0,0.0,0.25));
	AddParallel(new driveAuto(0.0,0.0,0.0,0.0,0.0));
	*/
}
