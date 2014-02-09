#include "Autonomous.h"

Autonomous::Autonomous() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	Requires(intake);
	
	//ticktock = new Timer();
}

// Called just before this Command runs the first time
void Autonomous::Initialize() {
	chassis->encoderReset();
	//ticktock->Reset();
	//ticktock->Start();
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute() {
	//intake->MoveSolenoid(false);
	
	chassis->tankDrive(0.25, 0.25);
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"  ";
	cout<<"Right Encoder: "<<chassis->encoderRightGet()<<"\n";
	
//	if(chassis->encoderLeftGet()<=1.0 && chassis->encoderRightGet()<=1.0) {
//		chassis->tankDrive(-0.25, -0.25);
////	} else if(!(chassis->encoderLeftGet()<=1440.0) && chassis->encoderRightGet()<=1440.0) {
////		chassis->tankDrive(0.0, -0.25);
////	} else if (chassis->encoderLeftGet()<=1440.0 && !(chassis->encoderRightGet()<=1440.0)) {
////		chassis->tankDrive(-0.25, 0.0);
//	} else {
//		chassis->tankDrive(0.0, 0.0);
//	}
	
	
	
	
//	//runs robot forward at 25% speed for 5 second
//		if(ticktock->Get()<= 5) {
//			cout<<"Run Motors\n";
//			chassis->tankDrive(-0.25, -0.25);
//		}
//		else {
//			//stops robot
//			cout<<"stop Motors\n";
//		}
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Autonomous::End() {
	chassis->tankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {
	chassis->tankDrive(0.0, 0.0);
}
