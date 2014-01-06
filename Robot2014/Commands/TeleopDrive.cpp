#include "TeleopDrive.h"

TeleopDrive::TeleopDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(driveBase);
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute() {
	driveBase->tankDrive(oi->getJoy1(), oi->getJoy2());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDrive::Interrupted() {
}
