#include "LindaCommand.h"

LindaCommand::LindaCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LindaCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LindaCommand::Execute() {
	printf("Button 3 pressed!");
}

// Make this return true when this Command no longer needs to run execute()
bool LindaCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LindaCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LindaCommand::Interrupted() {
}
