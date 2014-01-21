#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
    // TODO: Investigate moving these to robotmap.h
	static const int JOYSTICK_PORT1  = 1;
	static const int JOYSTICK_PORT2  = 2;
	
	static const int KICKER_BTN      = 1;
	static const int REVERSE_BTN     = 2;
	
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

public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	
	JoystickButton *Shift_Up_btn;
	JoystickButton *Shift_Down_btn;
};

#endif
