#include "MoveKicker.h"


/* MoveKicker::MoveKicker()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Takes control of Chassis Subsystem
*/
MoveKicker::MoveKicker(int m) {
	Requires(kicker);
	Mode = m;
}


/*MoveKicker::Initialize()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called just before this Command runs 
 * the first time
*/
void MoveKicker::Initialize() {
	speed = 0.00; 
}


/*MoveKicker::Execute()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called repeatedly when this Command is
 * scheduled to run
*/
void MoveKicker::Execute() {
	if (Mode == 0) {
		kicker->setSpeed(speed);
		
		if (speed>=0.75) {
			speed=0.75;
		}
		else {
			speed += 0.055;
		}
	}
	else {
		kicker->setSpeed(speed);
				
		if (speed<=-0.40) {
			speed=-0.40;
		}
		else {
			speed -= 0.055;
		}
	}
}


/*MoveKicker::IsFinished()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Make this return true when this Command no
 * longer needs to run execute()
*/
bool MoveKicker::IsFinished() {
	return false;
}


/*MoveKicker::End()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called once after isFinished returns true
*/
void MoveKicker::End() {
	kicker->setSpeed(0.0);
}


/*MoveKicker::Interrupted()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called when another command which requires 
 * one or more of the same subsystems is scheduled 
 * to run
*/
void MoveKicker::Interrupted() {
	kicker->setSpeed(0.0);
}
