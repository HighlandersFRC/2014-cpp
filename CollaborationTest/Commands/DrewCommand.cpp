#include "DrewCommand.h"

DrewCommand::DrewCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void DrewCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DrewCommand::Execute() {
}

void DrewCommand::Monkeys() {
	printf("Monkeys!");
}

// Make this return true when this Command no longer needs to run execute()
bool DrewCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrewCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrewCommand::Interrupted() {
}
