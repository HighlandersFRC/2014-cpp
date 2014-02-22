#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *joystick1;
	Joystick *joystick2;
	Joystick *joystick3;
	Joystick *joystick4;
	
public:
	OI();
	Joystick *getJoystick1();
	Joystick *getJoystick2();
	Joystick *getJoystick3();
	Joystick *getJoystick4();
	
	bool getBtn(const int[2]);
	double getAxis(const int[2]);
};

#endif
