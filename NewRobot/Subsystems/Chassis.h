#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>

class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon          *drive_left_1;
	Talon          *drive_left_2;
	Talon          *drive_right_1;
	Talon          *drive_right_2;
	
	Encoder        *left_encode;
	Gyro           *gyro_sens;
	DoubleSolenoid *shifter;
	
	double Pi;
	
	double cube(double);
	
public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(double, double);
	void tankExpDrive(double, double);
	void tankCosDrive(double, double);
	void arcadeDrive(Joystick *stick);
	void encoderReset();
	double encoderGet();
	void gyroReset();
	double getAngle();
	void setShifter(bool);
};

#endif
