#include "CanGrabAutoGroup.h"
#include "Commands/AutoCanGrabber.h"
#include "Commands/driveAuto.h"
#include "Commands/SetOffSet.h"
CanGrabAutoGroup::CanGrabAutoGroup()
{
	AddSequential(new SetOffSet(180));
	//AutoCanGrabber(wings, flopper, open_close);
	AddSequential(new AutoCanGrabber(true,false,true));
	AddSequential(new driveAuto(0.0,1.0,0.0,0.0,1));
	AddSequential(new AutoCanGrabber(false,true,true));
	AddSequential(new driveAuto(0.0,-1.0,0.0,0.0,1.5));
	AddSequential(new AutoCanGrabber(true,false,false));
	AddSequential(new AutoCanGrabber(false,true,false));
}
