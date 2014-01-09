#ifndef KICKERTEST_H
#define KICKERTEST_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Javario
 */
class Kickertest: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Kickertest();
	void InitDefaultCommand();
};

#endif
