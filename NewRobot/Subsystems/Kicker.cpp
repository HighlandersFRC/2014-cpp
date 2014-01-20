#include "Kicker.h"
#include "../Robotmap.h"
#include "../DebugPrint.h"

///Kicker::Kicker()
///
///@brief This function constructs the subsystem.
///
///This function does not take or return a value.
///
Kicker::Kicker() : Subsystem("Kicker") {
	motor_1 = new Victor(KICKER_MOTOR_1);
	motor_2 = new Victor(KICKER_MOTOR_2);
	this->setSpeed(0);
}


/*Kicker::InitDefaultCommand()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Sets default command for Kicker 
 * subsystem.
*/
void Kicker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new DriveWithJoystick());
	
	DebugPrint(1, "Setting Default Command for Kicker to none");
}

///Chassis::setSpeed()
///
///@brief This function moves the chassis based on y joystick axis position.
///
///@param left  : double argument for left joystick y-axis (range 1 to -1)
///@param right : double argument for right joystick y-axis (range 1 to -1)
///
///This function returns a distance in inches as a double.
///
void Kicker::setSpeed(double s) {
	motor_1->Set(s);
	motor_2->Set(s);
	KickerSpeed = s;
	SmartDashboard::PutNumber("Kicker Speed", KickerSpeed);
}
