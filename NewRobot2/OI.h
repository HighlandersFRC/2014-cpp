#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *driverLeftJoystick;
	Joystick *driverRightJoystick;
	Joystick *copilotLeftJoystick;
	Joystick *copilotRightJoystick;
	
public:
	OI();
	
	bool getBtn(const int[2]);
	
	double getAxisLeftDrive(const int axis[2]);
	double getAxisRightDrive(const int axis[2]);
	double getAxisCopilotLeft(const int axis[2]);
	double getAxisCopilotRight(const int axis[2]);
	
};

#endif
