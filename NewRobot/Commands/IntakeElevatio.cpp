#include "IntakeElevatio.h"

IntakeElevatio::IntakeElevatio(bool val) {
	Requires(nomos);
	solVal = val;
}

// Called just before this Command runs the first time
void IntakeElevatio::Initialize() {
	nomos->MoveSolenoid(false);
}

// Called repeatedly when this Command is scheduled to run
void IntakeElevatio::Execute() {
	nomos->MoveSolenoid(solVal);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeElevatio::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeElevatio::End() {
	nomos->MoveSolenoid(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeElevatio::Interrupted() {
}
