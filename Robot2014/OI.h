#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	static const int JOYSTICK_PORT1 = 1;
	static const int JOYSTICK_PORT2 = 2;
	Joystick *stick1;
	Joystick *stick2;

public:
	OI();
	
	Joystick *getJoy1();
	Joystick *getJoy2();
};

#endif
