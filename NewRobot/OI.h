#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *joystick_1;
	Joystick *joystick_2;
public:
	OI();
	Joystick* GetJoystick1();
	Joystick* GetJoystick2();
};

#endif
