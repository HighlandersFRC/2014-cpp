#include "OI.h"

// Include commands
#include "Commands/MoveKicker.h"
#include "Commands/IntakeCMD.h"
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
	stick1 = new Joystick(JOYSTICK_PORT1);
	stick2 = new Joystick(JOYSTICK_PORT2);
	
	Button1 = new JoystickButton(stick2, KICKER_BTN);
	Button1->WhileHeld(new MoveKicker(0));
	
	Button2 = new JoystickButton(stick2, REVERSE_BTN);
	Button2->WhileHeld(new MoveKicker(1));
	 
	Button3 = new JoystickButton(stick1, INTAKE_UP_BTN);
	Button3->WhileHeld(new IntakeCMD(0.2));
	
	Button4 = new JoystickButton(stick1, INTAKE_DOWN_BTN);
	Button4->WhileHeld(new IntakeCMD(-0.2));
	
	Button5 = new JoystickButton(stick1, INTAKE_STOP_BTN);
	Button5->WhileHeld(new IntakeCMD(0.0));
	
	Shift_Up_btn   = new JoystickButton(stick1, SHIFT_UP_BTN);
	
    Shift_Down_btn = new JoystickButton(stick1, SHIFT_DOWN_BTN);
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
	return stick1;
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
	return stick2;
}

