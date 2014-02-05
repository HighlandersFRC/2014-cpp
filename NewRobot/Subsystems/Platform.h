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
//	Encoder *Encoder;
public:
	Platform();
	void InitDefaultCommand();
	
	void setSpeed(double);
};

#endif
