#ifndef SENSORS_H
#define SENSORS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Sensors: public Subsystem {
private:
	AnalogChannel *DistanceSensor;
	Gyro *Gyroscope;
	
public:
	Sensors();
	void InitDefaultCommand();
	double get_DS_Distance();
	double get_Gyro_Distance();
	void Gyro_Reset();
	double get_V_Distance();
	double get_V_X();
	double get_V_Y();
	void Drive_Straight();
};

#endif
