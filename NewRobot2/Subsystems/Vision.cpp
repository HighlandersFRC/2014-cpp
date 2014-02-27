#include "Vision.h"
#include "../Robotmap.h"

Vision::Vision() : Subsystem("Vision") {
	DistanceSensor = new AnalogChannel(DIST_SENS);
}
    
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

// Returns distance in centimeters
double Vision::get_DS_Distance() {
	double distance = ((DistanceSensor->GetVoltage()/5)*1024);
	
	// Post data to SmartDashboard
	SmartDashboard::PutNumber(SD_DISTANCE, distance);
	
	return distance;
}

double Vision::get_V_Distance() {
	return SmartDashboard::GetNumber("Vision_Range");
}

double Vision::get_V_X() {
	return SmartDashboard::GetNumber("Vision_X");
}

double Vision::get_V_Y() {
	return SmartDashboard::GetNumber("Vision_Y");
}
