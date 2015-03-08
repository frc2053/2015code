#include <Commands/PneumaticsAuto.h>
#include "TwentyPointAuto.h"
#include "DriveAutoCorrect.h"
#include "WinchAuto.h"
#include "PneumaticsAuto.h"
#include "RotatetoAngle.h"
#include "DriveWhileWinching.h"
#include "SetOffSet.h"

TwentyPointAuto::TwentyPointAuto()
{
	//Grab first tote
		AddSequential(new PneumaticsAuto(true,true, false));

	//Get to Second Tote, Bumping Container out of the Way
		//Angle, Speed
		AddSequential(new RotatetoAngle(45,1));
		//Side Magnitude, Forward Magnitude, Rotation Magnitude, Position Yaw, Drive Time, Drive Angle, Winch Magnitude, Winch Time
		AddSequential(new DriveWhileWinching(1,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2, 45));
		AddSequential(new RotatetoAngle(-45,1));
		AddSequential(new DriveWhileWinching(-1,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2, -45));
		AddSequential(new RotatetoAngle(0,1));
		AddSequential(new DriveWhileWinching(0,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2,0));


	//At Second Tote, Lower First Down and Pick Up Both
		AddSequential(new WinchAuto(-1,0.5));
		AddSequential(new PneumaticsAuto(true,true, true));
		AddSequential(new WinchAuto(-0.5,1));
		AddSequential(new WinchAuto(0.0,0));
		AddSequential(new PneumaticsAuto(true,true, false));


	//Get to Third Tote, Bumping Container out of the Way
		//Angle, Speed
		AddSequential(new RotatetoAngle(45,1));
		//Side Magnitude, Forward Magnitude, Rotation Magnitude, Position Yaw, Drive Time, Drive Angle, Winch Magnitude, Winch Time
		AddSequential(new DriveWhileWinching(1,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2,45));
		AddSequential(new RotatetoAngle(-45,1));
		AddSequential(new DriveWhileWinching(-1,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2,-45));
		AddSequential(new RotatetoAngle(0,1));
		AddSequential(new DriveWhileWinching(0,-1,0.0,Robot::driveBaseSub->getAdjYaw(),.2,1,.2, -45));


	//At Third Tote, Lower Two Down and Pick Up Three
		AddSequential(new WinchAuto(-1,0.5));
		AddSequential(new PneumaticsAuto(true,true, true));
		AddSequential(new WinchAuto(-0.5,1));
		AddSequential(new WinchAuto(0.0,0));
		AddSequential(new PneumaticsAuto(true,true, false));


	//Lift all Totes and Get to AutoZone
		AddSequential(new DriveWhileWinching(1,0,0.0,Robot::driveBaseSub->getAdjYaw(),1,1,.5,90));
		AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//Drop Totes and Back Away
		AddSequential(new WinchAuto(-0.5,0.25));
		AddSequential(new DriveWhileWinching(0,0,0.0,Robot::driveBaseSub->getAdjYaw(),0,-1,.5, 0));
		AddSequential(new PneumaticsAuto(true,true, true));
		AddSequential(new DriveWhileWinching(0.0,1.0,0.0,Robot::driveBaseSub->getAdjYaw(),0.25,0.0,0.0,0));
		AddSequential(new DriveWhileWinching(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0));

	//passes angle offset
		AddSequential(new SetOffSet(-90));
}
