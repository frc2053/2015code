#include "CanandToteAuto.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "Commands/SetOffSet.h"
#include "Commands/RotatetoAngle.h"
#include "DriveAutoCorrect.h"

CanandToteAuto::CanandToteAuto()
{
	//AddSequential(new SetOffSet(0));//set off set to 0
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new WinchAuto(1, 1));//lift winch
	AddSequential(new DriveAutoCorrect(0,-0.5,0.0,Robot::driveBaseSub->getAdjYaw(),0.4,0));//drive fow
	AddSequential(new WinchAuto(-.5, .3));
	AddSequential(new PneumaticsAuto(true, true, true));//open arms
	AddSequential(new WinchAuto(-1, 1.5));//lower winch
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new WinchAuto(1,.5));
	AddSequential(new RotatetoAngle(-90, 1));
	AddSequential(new DriveAutoCorrect(-0.75,-0.1,0.0,Robot::driveBaseSub->getAdjYaw(),1.5,-90));//drive side
	AddSequential(new SetOffSet(90));//set off set to 90

}
