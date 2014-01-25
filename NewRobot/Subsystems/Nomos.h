#ifndef NOMOS_H
#define NOMOS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Drew
 */
class Nomos: public Subsystem {
private:
	DoubleSolenoid *sol;
public:
	Nomos();
	void InitDefaultCommand();
	void MoveSolenoid(bool);
};

#endif
