#include "AutoCommandGroup.h"
#include "DriveAuto.h"

AutoCommandGroup::AutoCommandGroup() {

	printf("\n In AutoCommandGroup::AutoCommandGroup() ");
	
	//DriveAuto(side, fow, rot, yaw, time);
	AddSequential(new DriveAuto(0.0, -0.3, 0.0, 0.0, 0.3));
	printf("\n Done AddSequential(new DriveAuto(0.0, -0.3, 0.0, 0.0, 0.3))");
	
	AddSequential(new DriveAuto(0.0, 0.4, 0.0, 0.0, 0.3));
	printf("\n Done AddSequential(new DriveAuto(0.0, 0.4, 0.0, 0.0, 0.3)) ");
	
	AddSequential(new DriveAuto(0.5, 0.0, 0.0, 0.0, 0.3));
	printf("\n Done AddSequential(new DriveAuto(0.5, 0.0, 0.0, 0.0, 0.3)) ");
	
}
