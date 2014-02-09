#include "Sensors.h"
#include "../Robotmap.h"
#include "../Commands/SensorsUpdate.h"

Sensors::Sensors() : Subsystem("Sensors") {
	DistanceSensor = new AnalogChannel(DIST_SENS);
	Gyroscope = new Gyro(GYRO_SENS);
}
    
void Sensors::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SensorsUpdate());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

// Returns distance in centimeters
double Sensors::get_DS_Distance() {
	double distance = ((DistanceSensor->GetVoltage()/5)*1024);
	
	// Post data to SmartDashboard
	SmartDashboard::PutNumber("Distance Sensor", distance);
	
	return distance;
}

double Sensors::get_Gyro_Distance() {
	double angle = Gyroscope->GetAngle();
	return angle;
}

void Sensors::Gyro_Reset() {
	Gyroscope->Reset();
}

void Sensors::Drive_Straight() {

	float angle = gyro.GetAngle();
	myRobot.Drive(-1.0, -angle * Kp);
	Wait(0.004);
}

double Sensors::get_V_Distance() {
	return SmartDashboard::GetNumber("Vision_Range");
}

double Sensors::get_V_X() {
	return SmartDashboard::GetNumber("Vision_X");
}

double Sensors::get_V_Y() {
	return SmartDashboard::GetNumber("Vision_Y");
}
