#include "Platform.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

Platform::Platform() : PIDSubsystem("Platform", 1.0, 0.0, 0.0) {
	Belt_Motor = new Jaguar(BELT_MOTOR);
	Belt_Pot   = new AnalogChannel(BELT_POT);
	SetInputRange(1.0f, 4.0f);
	//SetSetpoint(STOW);
	Enable();
}

double Platform::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return Belt_Pot->GetAverageVoltage();
}

void Platform::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Belt_Motor->PIDWrite(output);
}

void Platform::setSpeed(double speed) {
	Belt_Motor->SetSpeed(speed);
}

double Platform::getBeltPot() {
	voltage = Belt_Pot->GetVoltage();
	return voltage;
}

void Platform::setPIDValue(double p, double i, double d) {
	Kp = p;
	Ki = i;
	Kd = d;
}

void Platform::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
// Basic preset command to put the platform approximately one of our favorite
// Positions. this version does not contain PID or Vision Tracking.

//void request height (checks if at requested height)
//bool if button pressed = 0 (ignores joy (looks at requested height)), if joy = 1 (ignores button (skips requesed height))

//
void Platform::requestPosition(double wantedheight) {
	storeheight = wantedheight;
	curheight = Belt_Pot->GetVoltage();
	if (storeheight <= curheight & storeheight >= curheight) {
		//do nothing
	}
	else {
		this->setPosition(wantedheight);
	}
}

void Platform::setPosition(double height) {
	curheight = Belt_Pot->GetAverageVoltage();
	//posspeed = SmartDashboard::GetNumber("Position Movement");    //should be like .5
	if (height >= curheight - .01){                //.01 = Tolerance
		Belt_Motor->SetSpeed(posspeed);
	}
	else if (height <= curheight + .01){           //.01 = Tolerance
		Belt_Motor->SetSpeed(posspeed);
	}

}

/*
	if (platform->ReturnPIDInput() < platform_level) {
							platform->setSpeed(0.5);
							cout<<"test 2\n";
						}
						else {
							platform->setSpeed(-0.5);
							cout<<"test 3\n";
						}
						
						cout<<"test 4\n";
						
						if ((platform_level + TOLERANCE >= platform->ReturnPIDInput()) && (platform_level-TOLERANCE <= platform->ReturnPIDInput())) {
							cout<<"test 5\n";
							state = S_AS_SHOOT;
							platform->setSpeed(0.0);
						}
*/	

