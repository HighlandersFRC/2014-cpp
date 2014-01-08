#include "OI.h"


/* OI::OI()
 * Inputs  - 
 * 		None
 * Returns - 
 * 		None
 * 
 * Creates control objects and assigns
 * commands to events.
*/
OI::OI() {
	// Process operator interface input here.
	joystick_1 = new Joystick(1);
	joystick_2 = new Joystick(2);
}


/* OI::GetJoystick1()
 * Inputs  - 
 * 		None
 * Returns - 
 * 		Joystick*
 * 
 * Returns Joystick 1 pointer
*/
Joystick* OI::GetJoystick1() {
	return joystick_1;
}


/* OI::GetJoystick2()
 * Inputs  - 
 * 		None
 * Returns - 
 * 		Joystick*
 * 
 * Returns Joystick 2 pointer
*/
Joystick* OI::GetJoystick2() {
	return joystick_2;
}
