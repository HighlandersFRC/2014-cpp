#include "Autonomous.h"

Autonomous::Autonomous() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	Requires(intake);
//	ticktock1 = new Timer();
}

// Called just before this Command runs the first time
void Autonomous::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute() {
	intake->MoveSolenoid(false);
	
	//starts timer
//	ticktock.Start();
//	
//	//runs robot forward at 50% speed for 1 second
//	while(ticktock.GetFPGATimestamp()< 1) {
//		chassis->tankDrive(0.5, 0.5);
//	}
//	
//	//stops robot
//	chassis->tankDrive(0.0, 0.0);
	
	
	
	//	while(chassis->encoderGet()<2) {
//		chassis->tankDrive(0.5, 0.5);
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Autonomous::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {
}
