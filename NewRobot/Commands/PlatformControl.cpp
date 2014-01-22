#include "PlatformControl.h"

PlatformControl::PlatformControl() {
	// Use Requires() here to declare subsystem dependencies
	Requires(platform);
}

// Called just before this Command runs the first time
void PlatformControl::Initialize() {
	platform->setSpeed(0.0);
}

// Called repeatedly when this Command is scheduled to run
void PlatformControl::Execute() {
	platform->setSpeed(oi->getJoystick3()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool PlatformControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PlatformControl::End() {
	platform->setSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlatformControl::Interrupted() {
	platform->setSpeed(0.0);
}
