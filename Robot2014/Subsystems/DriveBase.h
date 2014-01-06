#ifndef DRIVEBASE_H
#define DRIVEBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Drew
 */
class DriveBase: public Subsystem {
private:
	RobotDrive *drive;

public:
	DriveBase();
	void InitDefaultCommand();
	void tankDriveAuto(double left, double right);		//for autonomous
	void tankDrive(Joystick *stick1, Joystick *stick2);		//with joysticks
};

#endif
