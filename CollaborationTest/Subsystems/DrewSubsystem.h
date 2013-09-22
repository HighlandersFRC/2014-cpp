#ifndef DREWSUBSYSTEM_H
#define DREWSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Drew
 */
class DrewSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DrewSubsystem();
	void InitDefaultCommand();
	void PrintMonkeys();
};

#endif
