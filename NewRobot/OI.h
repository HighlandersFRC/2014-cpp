#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	
	Joystick *joystick1;
	Joystick *joystick2;
	Joystick *joystick3;
	Joystick *joystick4;
	
<<<<<<< HEAD
	JoystickButton *kick_btn;
	JoystickButton *reload_btn;
	JoystickButton *shift_up_btn;
	JoystickButton *shift_down_btn;
	
=======
	static const int SHIFT_DOWN_BTN    = 2;
	
	static const int INTAKE_OUT_BTN   = 1;
	static const int INTAKE_IN_BTN = 1;
	
	Joystick *stick1;
	Joystick *stick2;
	JoystickButton *Button1;
	JoystickButton *Button2;
	JoystickButton *Button3;
	JoystickButton *Button4;
	JoystickButton *Button5;

>>>>>>> drewJ_compressor
public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	Joystick *getJoystick3();
	Joystick *getJoystick4();
	
	JoystickButton *getKickBtn();
	JoystickButton *getReloadBtn();
	JoystickButton *getShiftUpBtn();
	JoystickButton *getShiftDownBtn();
};

#endif
