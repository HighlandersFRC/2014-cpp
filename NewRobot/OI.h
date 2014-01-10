#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
	public:
		OI();
		
		// Controls
		Joystick *joystick_1;
		Joystick *joystick_2;
		JoystickButton *btn1;
};

#endif
