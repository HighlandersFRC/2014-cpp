#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * @author Zack Palmer
 */
class Drivetrain: public Subsystem {
	private:
		Victor *_MotorLeft;
		Victor *_MotorRight;
		bool   _Inverse_L;
		bool   _Inverse_R;
		double maxz(double, double);
		double minz(double, double);
		
	public:
		Drivetrain(int, int);
		void Init();
		void SetSpeeds(double, double);
		void TankDrive(double, double);
		void ArcadeDrive(double, double);
		void Stop();
		void SetInvert(bool, bool);
};

#endif
