#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
	private:
		// Controls
		Joystick *joystick_1;
		Joystick *joystick_2;
		
	public:
		OI();
		
		// Control Access Functions
		Joystick* GetJoystick1();
		Joystick* GetJoystick2();
};

#endif
