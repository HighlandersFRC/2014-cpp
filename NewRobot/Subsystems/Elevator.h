#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Javario
 */
class Elevator: public PIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *Belt_Motor;
	Encoder *Belt_Encoder;
	PIDController *pid;
public:
	Elevator();
	static const double BOTTOM = 4.6;
	static const double STOW = 1.65;
	static const double TABLE_HEIGHT = 1.58;
	void InitDefaultCommand();
	void setSpeed(double);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Reset();
	
};


#endif


/* PID
 * Input: float Kp, float Ki, float Kd, SmartDashboard.getvalue("Distance"), double Encoder::GetDistance(), double Encoder::GetRate()
 * Steps:
 * 1 - Zero Encoder using bottom Limit Switch.
 * 2 - Pull the wanted height from SmartDashboard.
 * 3 - Pull current height from Encoder.
 * 4 - 
 */
