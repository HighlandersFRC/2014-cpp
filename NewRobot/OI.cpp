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
	
	btn1       = new JoystickButton(1);
	//btn1->WhileHeld(DriveCMD);
}

