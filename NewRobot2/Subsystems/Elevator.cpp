#include "Elevator.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

Elevator::Elevator() : PIDSubsystem("Elevator", Kp, Ki, Kd) {
	Belt_Motor = new Jaguar(BELT_MOTOR);
	Belt_Encoder = new Encoder(BELT_ENCODER_A, BELT_ENCODER_B);
	SetSetpoint(STOW);
	Enable();
}

double Elevator::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	Belt_Encoder->PIDget();
	return 0.0;
}

void Elevator::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
