#include "LEDCmd.h"
int i = 0;
float LEDArray[44][3] =

{//Fade Black to Orange
{0,0,0},{0.1,0.01,0},{0.2,0.01,0},{0.3,0.02,0},{0.4,0.02,0},{0.5,0.03,0},{0.6,0.03,0},{0.7,0.04,0},{0.8,0.04,0},{0.9,0.05,0},{1,0.05,0},
 //Fade Orange to Black
{1,0.05,0},{0.9,0.05,0},{0.8,0.04,0},{0.7,0.04,0},{0.6,0.03,0},{0.5,0.03,0},{0.4,0.02,0},{0.3,0.02,0},{0.2,0.01,0},{0.1,0.01,0},{0,0,0},
 //Fade Black to Green
{0,0,0},{0.03,0.08,0},{0.05,0.15,0},{0.08,0.23,0},{0.11,0.3,0},{0.14,0.38,0},{0.16,0.46,0},{0.19,0.53,0},{0.22,0.61,0},{0.24,0.68,0},{0.27,0.76,0},
 //Fade Green to Black
{0.27,0.76,0},{0.24,0.68,0},{0.22,0.61,0},{0.19,0.53,0},{0.16,0.46,0},{0.14,0.38,0},{0.11,0.3,0},{0.08,0.23,0},{0.05,0.15,0},{0.03,0.08,0},{0,0,0}
};

LEDCmd::LEDCmd()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::ledsub);
}

// Called just before this Command runs the first time
void LEDCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LEDCmd::Execute()
{
	if(i == 43)
	{
		i = 0;
	}
	RobotMap::Red_LED->DisablePWM();
	RobotMap::Blue_LED->DisablePWM();
	RobotMap::Green_LED->DisablePWM();
	RobotMap::Red_LED->EnablePWM(LEDArray[i][0]);
	RobotMap::Blue_LED->EnablePWM(LEDArray[i][1]);
	RobotMap::Green_LED->EnablePWM(LEDArray[i][2]);

	printf("Red%.2f\n", LEDArray[i][0]);
	printf("Green%.2f\n", LEDArray[i][1]);
	printf("Blue%.2f\n", LEDArray[i][2]);
	printf("Timer loop\n%d", i);
	i++;
}

// Make this return true when this Command no longer needs to run execute()
bool LEDCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LEDCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDCmd::Interrupted()
{

}
