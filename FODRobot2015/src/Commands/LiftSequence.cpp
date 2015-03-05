#include "LiftSequence.h"
#include "winchAuto.h"
#include "PneumaticsAuto.h"

LiftSequence::LiftSequence()
{
	AddSequential(new PneumaticsAuto(true, true, true)); //lets go just to make sure
	AddSequential(new PneumaticsAuto(true, true, false)); //grabs second tote
	AddSequential(new WinchAuto(1, 1)); //winches up to put second on one just dropped in
	AddSequential(new PneumaticsAuto(true, true, true)); //lets go to put second on top of one dropped in
	AddSequential(new WinchAuto(-1, 1)); //winches down to tote just put in
}
