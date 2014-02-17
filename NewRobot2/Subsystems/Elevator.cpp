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

void Elevator::setSpeed(double speed) {
	Belt_Motor->SetSpeed(speed);
}

double Elevator::getBeltPot() {
	return Belt_Pot->GetVoltage();
}

void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
// Basic preset command to put the platform approximately one of our favorite
// Positions. this version does not contain PID or Vision Tracking.
void Elevator::setPosition(double height) {
	curheight = Belt_Pot->GetVoltage();
	posspeed = SmartDashboard::GetNumber("Position Movement");
	if (height > curheight - .05){
		Belt_Motor->SetSpeed(posspeed);
	}
	else if (height < curheight + .05){
		Belt_Motor->SetSpeed(posspeed);
	}
	else {
		Belt_Motor->SetSpeed(0);
	}
	
}
