#include "DriveCMD.h"
#include "..\CommandBase.h"


DriveCMD::DriveCMD() {
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DriveCMD::Initialize() {
	drivetrain->Stop();
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute() {
	drivetrain->TankDrive(oi->GetJoystick1()->GetY(), oi->GetJoystick2()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCMD::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCMD::Interrupted() {
	drivetrain->Stop();
}
