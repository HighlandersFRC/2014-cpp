#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *joystick1;
	Joystick *joystick2;
	Joystick *joystick3;
	Joystick *joystick4;

	JoystickButton *kick_btn;
	JoystickButton *reload_btn;
	
	JoystickButton *shifter_btn;
	
	JoystickButton *intake_engage_btn;
	
	JoystickButton *platform_up_btn;
	JoystickButton *platform_down_btn;

public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	Joystick *getJoystick3();
	Joystick *getJoystick4();
	
	JoystickButton *getKickBtn();
	JoystickButton *getReloadBtn();
	
	JoystickButton *getShifterBtn();
	JoystickButton *getIntakeEngageBtn();
	JoystickButton *getPlatformUpBtn();
	JoystickButton *getPlatformDownBtn();
};

#endif
