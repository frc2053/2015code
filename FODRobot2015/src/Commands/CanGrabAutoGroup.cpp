#include "CanGrabAutoGroup.h"
#include "Commands/AutoCanGrabber.h"
#include "Commands/driveAuto.h"
#include "Commands/SetOffSet.h"
CanGrabAutoGroup::CanGrabAutoGroup()
{
	//AutoCanGrabber(wings, flopper, open_close);
	AddSequential(new AutoCanGrabber(true,false,false));
	AddSequential(new driveAuto(0.0,1,0.0,0.0,.5));
	AddSequential(new AutoCanGrabber(false,true,false));
	AddSequential(new driveAuto(0,0,0,0,1.75));
	AddSequential(new driveAuto(0.0,-.5,0.0,0.0,1));
	AddSequential(new AutoCanGrabber(true,false,true));
	AddSequential(new AutoCanGrabber(false,true,true));
	//AddSequential(new SetOffSet(180));
}
