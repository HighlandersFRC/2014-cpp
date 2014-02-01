#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem {
private:
	AnalogChannel *DistanceSensor;
	
public:
	Vision();
	void InitDefaultCommand();
	double get_DS_Distance();
	double get_V_Distance();
	double get_V_X();
	double get_V_Y();
};

#endif
