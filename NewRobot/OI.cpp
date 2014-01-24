#include "OI.h"
#include "RobotMap.h"


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
	joystick1 = new Joystick(JOYSTICK_PORT1);
	joystick2 = new Joystick(JOYSTICK_PORT2);
	joystick3 = new Joystick(JOYSTICK_PORT3);
	joystick4 = new Joystick(JOYSTICK_PORT4);
	
	kick_btn = new JoystickButton(joystick2, KICK_BTN);
	kick_btn->WhileHeld(new MoveKicker(0));
	
	reload_btn = new JoystickButton(joystick2, RELOAD_BTN);
	reload_btn->WhileHeld(new MoveKicker(1));
	
	
	kick_btn	   = new JoystickButton(joystick4, KICK_BTN);

	reload_btn     = new JoystickButton(joystick4, RELOAD_BTN);
	
	shift_up_btn   = new JoystickButton(joystick1, SHIFT_UP_BTN);
	
    shift_down_btn = new JoystickButton(joystick1, SHIFT_DOWN_BTN);
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

JoystickButton* OI::getKickBtn() {
	return kick_btn;
}

JoystickButton* OI::getReloadBtn() {
	return reload_btn;
}

JoystickButton* OI::getShiftUpBtn() {
	return shift_up_btn;
}

JoystickButton* OI::getShiftDownBtn() {
	return shift_down_btn;
}
