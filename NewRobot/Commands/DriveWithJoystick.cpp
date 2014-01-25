#include "DriveWithJoystick.h"

/* DriveWithJoystick::DriveWithJoystick()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Takes control of Chassis Subsystem
*/
DriveWithJoystick::DriveWithJoystick() {
	Requires(chassis);
}


/*DriveWithJoystick::Initialize()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called just before this Command runs 
 * the first time
*/
void DriveWithJoystick::Initialize() {
	
}


/*DriveWithJoystick::Execute()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called repeatedly when this Command is
 * scheduled to run
*/
void DriveWithJoystick::Execute() {
	chassis->tankDrive(oi->getJoystick1()->GetY(), oi->getJoystick2()->GetY());
	
	//chassis->tankCosDrive(oi->getJoystick1()->GetY(), oi->getJoystick2()->GetY());
	
	//cout<<"Motor Encoder: "<<chassis->encoderGet()<<"\n";
	//cout<<"Gyro: "<<chassis->getAngle()<<"\n";
	
	chassis->setShifter(oi->getShiftDownBtn()->Get());
}


/*DriveWithJoystick::IsFinished()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Make this return true when this Command no
 * longer needs to run execute()
*/
bool DriveWithJoystick::IsFinished() {
	return false;
}


/*DriveWithJoystick::End()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called once after isFinished returns true
*/
void DriveWithJoystick::End() {
	
}


/*DriveWithJoystick::Interrupted()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Called when another command which requires 
 * one or more of the same subsystems is scheduled 
 * to run
*/
void DriveWithJoystick::Interrupted() {
}
