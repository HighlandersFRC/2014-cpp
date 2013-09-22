#ifndef LINDASUBSYSTEM_H
#define LINDASUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Linda
 */
class LindaSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LindaSubsystem();
	void InitDefaultCommand();
};

#endif
