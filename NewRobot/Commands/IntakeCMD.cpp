#include "IntakeCMD.h"

IntakeCMD::IntakeCMD(double num) {
	// Use requires() here to declare subsystem dependencies
	Requires(intake);
//	speed = num;
	speed = SmartDashboard::GetNumber("Intake Speed");
	val = num;
}

// Called just before this Command runs the first time
void IntakeCMD::Initialize() {
	intake->Set(0.0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeCMD::Execute() {
	if(val > 0) {
		intake->Set(speed);
	}
	if(val < 0) {
		intake->Set(speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeCMD::End() {
	intake->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCMD::Interrupted() {
	intake->Set(0.0);
}
