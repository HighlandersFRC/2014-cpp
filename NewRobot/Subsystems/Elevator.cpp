#include "Elevator.h"
#include "../Robotmap.h"
#include "../Commands/PlatformControl.h"

/* The platform needs two limit switches (one at the top and one at the bottom) to stop
 * the platform if it gets too close to the end. It will also have an encoder to measure
 * the height of the platform, so it may have functionality compatible with the vision
 * software in the future. For now, add buttons for the driver to run it up and down.
*/






//NOTE: THIS CODE LIKELY DOESN'T WORK, SINCE LINDA HAS NOT HAD A CHANCE TO TEST IT WITH
//A FUNCTIONAL ROBOT AND IS AT ALL-STATE CHOIR AS OF THE THURSDAY, FRIDAY, AND SATURDAY
//BEFORE THE FIRST ROBOT SHOWCASE. KNOWING THIS, SHE HAS COMMENTED ALL CODE IN THIS FILE
//THAT SHOULD ACTUALLY DO ANYTHING, SO THIS CODE SHOULD NOT CAUSE ANY PROBLEMS. IF IT
//DOES, EITHER COMMENT OUT CODE MESSING IT UP OR DELETE IT FROM MASTER IF IT IS ON MASTER.









Elevator::Elevator() : PIDSubsystem("Elevator", 1.0, 0,0, 0.0) {
	GetPIDController()->SetContinuous(false);
	Belt_Motor = new Jaguar(BELT_MOTOR);
	Belt_Encoder = new Encoder(BELT_ENCODER_A, BELT_ENCODER_B);
	SetSetpoint(STOW);
	Enable();
}
void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Command());
}


double Elevator::ReturnPIDInput() {
//	return Belt_Encoder->PIDGet();
}

void Elevator::UsePIDOutput(double output) {
//	Belt_Motor->PIDWrite(output);
}

void Elevator::Reset() {
//	Belt_Encoder->Reset();
}
