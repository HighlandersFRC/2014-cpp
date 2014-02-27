#include "OI.h"
#include "Joystickmap.h"
#include "SmartDashboard/SmartDashboard.h"

/*OI::OI()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Instilizes the operator interfaces
*/
OI::OI() 
{
	driverLeftJoystick   = new Joystick(DRIVER_LEFT_JOYSTICK);
	driverRightJoystick  = new Joystick(DRIVER_RIGHT_JOYSTICK);
	copilot  = new Joystick(COPILOT);
}

bool OI::getBtn(const int btn[2]) 
{
	Joystick *j   = new Joystick(btn[1]);
	bool isPushed = j->GetRawButton(btn[0]);
	delete j;
	return isPushed;
}

double OI::getAxisLeftDrive(const int axis[2]) 
{
	return driverLeftJoystick->GetRawAxis(axis[0]);
}

double OI::getAxisRightDrive(const int axis[2]) 
{
	return driverRightJoystick->GetRawAxis(axis[0]);
}

double OI::getAxisCopilot(const int axis[2]) 
{
	return copilot->GetRawAxis(axis[0]);
}
