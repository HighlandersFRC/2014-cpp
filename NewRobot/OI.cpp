#include "OI.h"
#include "RobotMap.h"


// Include commands
#include "Commands/MoveKicker.h"
#include "Commands/IntakeCMD.h"
#include "Commands/IntakeElevatio.h"
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
	
	kick_btn = new JoystickButton(joystick4, KICK_BTN);
	kick_btn->WhileHeld(new MoveKicker(0));
	
	reload_btn = new JoystickButton(joystick4, RELOAD_BTN);
	reload_btn->WhileHeld(new MoveKicker(1));
	
	intake_out_btn = new JoystickButton(joystick1, INTAKE_OUT_BTN);
	intake_out_btn->WhileHeld(new IntakeCMD(-1));
	
	intake_in_btn = new JoystickButton(joystick2, INTAKE_IN_BTN);
	intake_in_btn->WhileHeld(new IntakeCMD(1));
	
	intake_elevate_down = new JoystickButton(joystick1, INTAKE_ELEVATE_DOWN);
	intake_elevate_down->WhenPressed(new IntakeElevatio(false));
	
	intake_elevate_up = new JoystickButton(joystick1, INTAKE_ELEVATE_UP);
	intake_elevate_up->WhenPressed(new IntakeElevatio(true));
	
	//shift_up_btn   = new JoystickButton(joystick2, SHIFT_UP_BTN);
	
    shift_down_btn = new JoystickButton(joystick2, SHIFT_DOWN_BTN);
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

//JoystickButton* OI::getShiftUpBtn() {
//	return shift_up_btn;
//}

JoystickButton* OI::getShiftDownBtn() {
	return shift_down_btn;
}
