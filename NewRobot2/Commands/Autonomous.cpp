#include "Autonomous.h"

Autonomous::Autonomous() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	Requires(intake);
	
	chassis->encoderReset();
	ticktock = new Timer();
	state = S_INIT;
}

// Called just before this Command runs the first time
void Autonomous::Initialize() {
	//chassis->encoderReset();

	chassis->encoderReset();
	state = S_INIT;
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute() {
	
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"    Right  Encoder: "<<chassis->encoderRightGet();
	
	switch(state) {
		case S_INIT:
			ticktock->Reset();
			ticktock->Start();
			state = S_PICK_UP;
			cout<<"S_INIT\n";
			break;
	
	
		case S_PICK_UP:
			intake->MoveSolenoid(true);
			intake->Set(-1.0);
			cout<<"S_PICK_UP\n";
			
			if (ticktock->Get()>=2.0) {
				state = S_LOAD;
				ticktock->Reset();
				ticktock->Start();
			}
			else {
				state = S_PICK_UP;
			}
			break;
		
		case S_LOAD:
			chassis->tankDrive(0.25, 0.25);
			
			
			cout<<"S_LOAD\n";
			if (ticktock->Get()>=1.75) {
				state = S_FIRE;
				ticktock->Reset();
				ticktock->Start();
			}
			else {
				state = S_LOAD;
			}
			break;
		
		case S_FIRE:
			cout<<"S_FIRE\n";
			intake->MoveSolenoid(false);
			intake->Set(0.0);
			chassis->tankDrive(0.0, 0.0);
			state = S_FIRE;
			break;
			
		default:
			state = S_INIT;
			break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Autonomous::End() {
	chassis->tankDrive(0.0, 0.0);
	state = S_INIT;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {
	chassis->tankDrive(0.0, 0.0);
	state = S_INIT;
}
