#ifndef PLATFORM_H
#define PLATFORM_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Javario
 */
class Platform: public PIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	Jaguar *Belt_Motor;
	AnalogChannel *Belt_Pot;
	
	static const double STOW = 1.4;
	double Kp;
	double Ki;
	double Kd;
	double curheight;
	double posspeed;
	double voltage;
	double storeheight;
public:
	Platform();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void setPIDValue(double, double, double);
	void InitDefaultCommand();
	void setSpeed(double speed);
	double getBeltPot();
	void setPosition(double position);
	void requestPosition(double wantedheight);
};

#endif
