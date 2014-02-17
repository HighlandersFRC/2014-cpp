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
	// set the P, I, and D constants here
		Jaguar *Belt_Motor;
		AnalogChannel *Belt_Pot;
		PIDController *pid;
	static const double STOW = 1.65;
	static const double Kp = 0.1;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	double curheight;
	double posspeed;
public:
	Elevator();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void setSpeed(double speed);
	double getBeltPot();
	void setPosition(double position);
	
};

#endif
