#include "CanandToteAuto.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "Commands/SetOffSet.h"
#include "DriveAutoCorrect.h"

CanandToteAuto::CanandToteAuto()
{
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new WinchAuto(1, 1.5));//lift winch
	AddSequential(new DriveAutoCorrect(-0.75,0.0,0.0,Robot::driveBaseSub->getAdjYaw(),1,0));//drive left
	AddSequential(new WinchAuto(1, 0.5));//lower winch
	AddSequential(new PneumaticsAuto(true, true, true));//open   arms
	AddSequential(new WinchAuto(1, 1.0));//lift winch
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new DriveAutoCorrect(0.0,0.5,0.0,Robot::driveBaseSub->getAdjYaw(),2.0,0));//drive back
	AddSequential(new SetOffSet(180));

}
