#ifndef KICKER_H
#define KICKER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Kicker: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *motor_1;
	Victor *motor_2;

public:
	Kicker();
	void InitDefaultCommand();
	void setSpeed(double);
};

#endif
