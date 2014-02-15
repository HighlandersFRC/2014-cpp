#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <math.h>

//#define USE_DISTANCE_PER_PULSE 1

class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon          *drive_left_1;
	Talon          *drive_left_2;
	Talon          *drive_right_1;
	Talon          *drive_right_2;
	
	Encoder        *left_encode;
	Encoder 	   *right_encode;
	Gyro           *gyro_sens;
	DoubleSolenoid *shifter;
	
#if (USE_DISTANCE_PER_PULSE == 1)	
	Timer *distance_clk;
	double distance_last;
#endif
	
	double Pi;
	
	double cube(double);
	
public:
	Chassis();
	void InitDefaultCommand();
	void tankDrive(double, double);
	void tankExpDrive(double, double);
	void tankCosDrive(double, double);
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)		
	void arcadeDrive(double, double);
#endif	
	void encoderReset();
	double encoderLeftGet();
	double encoderRightGet();
	void gyroReset();
	double getAngle();
	void setShifter(bool);
};

#endif
