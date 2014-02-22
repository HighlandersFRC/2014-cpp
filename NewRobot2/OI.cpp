#include "OI.h"
#include "Joystickmap.h"
#include "SmartDashboard/SmartDashboard.h"

/*OI::OI()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Instilizes the operator interfaces
*/
OI::OI() {
	
	joystick1 = new Joystick(DRIVER_LEFT_JOYSTICK);
	joystick2 = new Joystick(DRIVER_RIGHT_JOYSTICK);
	joystick3 = new Joystick(COPILOT_LEFT_JOYSTICK);
	joystick4 = new Joystick(COPILOT_RIGHT_JOYSTICK);
}


/*OI::getJoystick1()
 * Inputs  -
 * 	None
 * Returns -
 * 	joystick (Joystick*) 
 * 
 * Returns joystick 1
*/
Joystick* OI::getJoystick1() {
	return joystick1;
}


/*OI::getJoystick2()
 * Inputs  -
 * 	None
 * Returns -
 * 	joystick (Joystick*) 
 * 
 * Returns joystick 2
*/
Joystick* OI::getJoystick2() {
	return joystick2;
}
Joystick* OI::getJoystick3() {
	return joystick3;
}
Joystick* OI::getJoystick4() {
	return joystick4;
}

bool OI::getBtn(const int btn[2]) {
	Joystick *j = new Joystick(btn[1]);
	return j->GetRawButton(btn[0]);
}

double OI::getAxis(const int axis[2]) {
	Joystick *j = new Joystick(axis[1]);
	return j->GetRawAxis(axis[0]);
}
