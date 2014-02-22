#include "Kicker.h"
#include "../Robotmap.h"

///Kicker::Kicker()
///
///@brief This function constructs the subsystem.
///
///This function does not take or return a value.
///
Kicker::Kicker() : Subsystem("Kicker") {
	motor_1 = new Victor(KICKER_MOTOR_1);
	motor_2 = new Victor(KICKER_MOTOR_2);
	setSpeed(0);
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
}

///Chassis::setSpeed()
///
///@brief This function moves the chassis based on y joystick axis position.
///
///@param s  : double argument for kicker speed (range 1 to -1)
///
///This function does not return anything
///
void Kicker::setSpeed(double s) {
	motor_1->Set(s);
	motor_2->Set(s);
	SmartDashboard::PutNumber(SD_KICKER_CURRENT_SPEED, s);
}
