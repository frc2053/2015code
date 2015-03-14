#include "CanandToteAuto.h"
#include "driveAuto.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "Commands/SetOffSet.h"
#include "DriveAutoCorrect.h"

CanandToteAuto::CanandToteAuto()
{
	//AddSequential(new SetOffSet(0));//set off set to 0
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new WinchAuto(1, 1));//lift winch
	AddSequential(new DriveAutoCorrect(-0.75,0.0,0.0,Robot::driveBaseSub->getAdjYaw(),0.9,0));//drive left
	AddSequential(new DriveAutoCorrect(0,-0.4,0,Robot::driveBaseSub->getAdjYaw(), 0.4, 0));
	AddSequential(new PneumaticsAuto(true, true, true));//open arms
	AddSequential(new WinchAuto(-1, 1.6));//lower winch
	AddSequential(new PneumaticsAuto(true, true, false));//close  arms
	AddSequential(new DriveAutoCorrect(0.0,0.5,0.0,Robot::driveBaseSub->getAdjYaw(),2.0,0));//drive back
	AddSequential(new SetOffSet(180));//set off set to 180

}
