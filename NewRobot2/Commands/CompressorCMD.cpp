#include "CompressorCMD.h"


CompressorCMD::CompressorCMD() {
	// Use requires() here to declare subsystem dependencies
	Requires(aircompressor);
}

// Called just before this Command runs the first time
void CompressorCMD::Initialize() {
	aircompressor->Start();
}

// Called repeatedly when this Command is scheduled to run
void CompressorCMD::Execute() {
	aircompressor->Update();
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CompressorCMD::End() {
	aircompressor->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorCMD::Interrupted() {
}
