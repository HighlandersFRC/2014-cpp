#include "Elevator.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

Elevator::Elevator() : PIDSubsystem("Elevator", Kp, Ki, Kd) {
	Belt_Motor = new Jaguar(BELT_MOTOR);
	Belt_Pot   = new AnalogChannel(BELT_POT);
	SetSetpoint(STOW);
	Enable();
}

double Elevator::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return Belt_Pot->GetAverageVoltage();
}

void Elevator::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Belt_Motor->Set(output);
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
