#ifndef PLATFORM_H
#define PLATFORM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Platform: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *Belt_Motor;
	Encoder *Belt_Encoder;
	PIDController *pid;
public:
	Platform();
	void InitDefaultCommand();
	void setSpeed(double);
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
