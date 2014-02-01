#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Intake: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *intakeRollers;
	DoubleSolenoid *sol;
public:
	Intake();
	void InitDefaultCommand();
	void Set(double);
	void MoveSolenoid(bool);
};

#endif
