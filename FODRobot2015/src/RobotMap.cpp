// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANJaguar* RobotMap::driveBaseSubFrontRightJag = NULL;
CANJaguar* RobotMap::driveBaseSubFrontLeftJag = NULL;
CANJaguar* RobotMap::driveBaseSubBackRightJag = NULL;
CANJaguar* RobotMap::driveBaseSubBackLeftJag = NULL;
RobotDrive* RobotMap::driveBaseSubRobotDrive = NULL;
DoubleSolenoid* RobotMap::RightGripper = NULL;
DoubleSolenoid* RobotMap::LeftGripper = NULL;
CANJaguar* RobotMap::winchJag = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//LiveWindow* lw = LiveWindow::GetInstance();

	RightGripper = new DoubleSolenoid(1,2);

	LeftGripper = new DoubleSolenoid(3,4);

	winchJag = new CANJaguar(1);

	driveBaseSubFrontRightJag = new CANJaguar(9);
	
	
	driveBaseSubFrontLeftJag = new CANJaguar(8);
	
	
	driveBaseSubBackRightJag = new CANJaguar(2);
	
	
	driveBaseSubBackLeftJag = new CANJaguar(6);
	
	
	driveBaseSubRobotDrive = new RobotDrive(driveBaseSubFrontLeftJag, driveBaseSubBackLeftJag,
              driveBaseSubFrontRightJag, driveBaseSubBackRightJag);
	
	driveBaseSubRobotDrive->SetSafetyEnabled(false);
        driveBaseSubRobotDrive->SetExpiration(0.1);
        driveBaseSubRobotDrive->SetSensitivity(0.5);
        driveBaseSubRobotDrive->SetMaxOutput(1.0);

        driveBaseSubRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveBaseSubRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
