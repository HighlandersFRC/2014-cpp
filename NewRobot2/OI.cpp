#include "OI.h"
#include "RobotMap.h"
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
	
	kick_btn          = new JoystickButton(joystick2, KICK_BTN);
	reload_btn        = new JoystickButton(joystick2, RELOAD_BTN);
	
		
	shifter_btn       = new JoystickButton(joystick1, SHIFTER_BTN);
		
	intake_engage_btn = new JoystickButton(joystick1, INTAKE_ENGAGE_BTN);
	
	platform_up_btn   = new JoystickButton(joystick1, PLATFORM_UP_BTN);
	platform_down_btn = new JoystickButton(joystick1, PLATFORM_DOWN_BTN);
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
JoystickButton* OI::getShifterBtn(){
	return shifter_btn;
}
JoystickButton* OI::getIntakeEngageBtn(){
	return intake_engage_btn;
}
JoystickButton* OI::getPlatformUpBtn(){
	return platform_up_btn;
}
JoystickButton* OI::getPlatformDownBtn(){
	return platform_down_btn;
}


bool OI::getBtn(const int btn[2]) {
	Joystick *j = new Joystick(btn[1]);
	return j->GetRawButton(btn[0]);
}

double OI::getAxis(const int axis[2]) {
	Joystick *j = new Joystick(axis[1]);
	return j->GetRawAxis(axis[0]);
}
