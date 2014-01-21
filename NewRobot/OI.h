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
	
	static const int SHIFT_UP_BTN    = 3;
	static const int SHIFT_DOWN_BTN  = 4;
	
	static const int KICK_BTN  		 = 1;
	static const int KICK_PREP_BTN   = 2;
	
	
	Joystick *stick1;
	Joystick *stick2;
	Joystick *stick3;
	Joystick *stick4;
	JoystickButton *Button1;
	JoystickButton *Button2;

public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	
	JoystickButton *Shift_Up_btn;
	JoystickButton *Shift_Down_btn;
	
	JoystickButton *Kick_Btn;
	JoystickButton *Kick_Prep_Btn;
	
};

#endif
