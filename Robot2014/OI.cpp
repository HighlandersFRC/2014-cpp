#include "OI.h"

OI::OI() {
	stick1 = new Joystick(JOYSTICK_PORT1);
	stick2 = new Joystick(JOYSTICK_PORT2);
	
	// Process operator interface input here.
}

Joystick* OI::getJoy1() {
	return stick1;
}
Joystick* OI::getJoy2() {
	return stick2;
}


