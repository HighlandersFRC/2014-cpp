#include "OI.h"

OI::OI() {
	// Process operator interface input here.
	joystick_1 = new Joystick(1);
	joystick_2 = new Joystick(2);
}
Joystick* OI::GetJoystick1() {
	return joystick_1;
}
Joystick* OI::GetJoystick2() {
	return joystick_2;
}

