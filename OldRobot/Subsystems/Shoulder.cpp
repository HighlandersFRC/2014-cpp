// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shoulder.h"
#include "../Robotmap.h"
Shoulder::Shoulder() : Subsystem("Shoulder") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	shoulderMotor = RobotMap::shoulderShoulderMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	bool locked = true;
}
void Shoulder::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Shoulder::SetShoulder(double pwr) {
	//if (!locked) {
	            shoulderMotor->Set(pwr);
	       // }
}
void Shoulder::SetLock(bool on) {
//	lock->set(!on);
//	        if (!on) {
//	            locked = false;
//	        }
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
