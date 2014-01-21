#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI {
private:
	Joystick *joystick1;
	Joystick *joystick2;
	Joystick *joystick3;
	JoystickButton *kick_btn;
	JoystickButton *reload_btn;
	JoystickButton *shift_up_btn;
	JoystickButton *shift_down_btn;
	
public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	Joystick *getJoystick3();
	JoystickButton *getKickBtn();
	JoystickButton *getReloadBtn();
	JoystickButton *getShiftUpBtn();
	JoystickButton *getShiftDownBtn();
};

#endif
