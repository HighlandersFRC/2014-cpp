#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *driverLeftJoystick;
	Joystick *driverRightJoystick;
	Joystick *copilot;
	
public:
	OI();
	
	bool getBtn(const int[2]);
	
	double getAxisLeftDrive(const int axis[2]);
	double getAxisRightDrive(const int axis[2]);
	double getAxisCopilot(const int axis[2]);
	
};

#endif
