#ifndef PLATFORM_H
#define PLATFORM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class Platform: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *Belt_Motor;

public:
	Platform();
	void InitDefaultCommand();
	
	void setMotorSpeed(double);
	void calibrate();
	void moveToPos(double);
};

#endif
