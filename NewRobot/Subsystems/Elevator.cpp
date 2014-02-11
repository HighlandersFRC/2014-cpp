#include "Elevator.h"
#include "../Robotmap.h"
#include "../Commands/PlatformControl.h"

/* The platform needs two limit switches (one at the top and one at the bottom) to stop
 * the platform if it gets too close to the end. It will also have an encoder to measure
 * the height of the platform, so it may have functionality compatible with the vision
 * software in the future. For now, add buttons for the driver to run it up and down.
*/






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
