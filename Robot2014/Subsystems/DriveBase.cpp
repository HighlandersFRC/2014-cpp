#include "DriveBase.h"
#include "../Robotmap.h"
#include "../Commands/TeleopDrive.h"

DriveBase::DriveBase() : Subsystem("DriveBase") {
	drive = new RobotDrive(1, 2);
	drive->SetSafetyEnabled(false);
}
    
void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new TeleopDrive);
}
void DriveBase::tankDriveAuto(double left, double right) {
	drive->TankDrive(left, right);
}
void DriveBase::tankDrive(Joystick *stick1, Joystick *stick2) {
	drive->TankDrive(stick1, stick2);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
