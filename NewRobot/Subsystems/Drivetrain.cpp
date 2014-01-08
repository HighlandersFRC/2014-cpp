#include "Drivetrain.h"
#include "../Robotmap.h"
#include "../Commands/DriveCMD.h"

/* Drivetrain(int, int)
 * Inputs  - 
 * 		int Left motor  (PWM port)
 * 		int Right motor (PWM port)
 * Returns - 
 * 		Drivetrain
 * 
 * Creates Motors method call values (int)
*/
Drivetrain::Drivetrain(int l, int r) : Subsystem("ExampleSubsystem") {
	_MotorLeft  = new Victor(l); 	// Define left victor
	_MotorRight = new Victor(r); 	// Define right victor
}
    
void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveCMD());
}


/* Drivetrain::SetSpeeds(int, int)
 * Inputs  - 
 * 		Left motor speed  (range 1 to -1)
 * 		Right motor speed (range 1 to -1)
 * Returns - 
 * 		None
 * 
 * Sets PWM rate corresponding to motor. If the
 * value is out of range, then the motors will
 * be stoped.
*/
void Drivetrain::SetSpeeds(double l, double r) {
	bool Error = false;
	Error |= (l < -1 || l > -1);    // Check if left speed is in range
	Error |= (r < -1 || r > -1);    // Check if right speed is in range
	
	if (_Inverse_L) {               // Invert left speed if needed
		l *= -1;
	}
	if (_Inverse_R) {               // Invert right speed if needed
		r *= -1;
	}
	
	if (Error) {                    // Check for error
		this->Stop();                // Stop motors if error is true
	}
	else {
		_MotorLeft->Set(l);         // Set Left motor speed
		_MotorRight->Set(r);        // Set Right motor speed
	}
}


/* Drivetrain::TankDrive(double, double)
 * Inputs  - 
 * 		Left motor speed  (range 1 to -1)
 * 		Right motor speed (range 1 to -1)
 * Returns - 
 * 		None
 * 
 * Sets PWM rate corresponding to motor. If the
 * value is out of range, then the motors will
 * be stoped.
*/
void Drivetrain::TankDrive(double x1, double x2) {
	bool Error = false;
    Error |= (x1 < -1 || x1 > -1);  // Check if left joystick is in range
	Error |= (x2 < -1 || x2 > -1);  // Check if right joystick is in range
	
	if (Error) {
		this->Stop();                // Stop Motors if error
	}
	else {
		this->SetSpeeds(x1, x2);     // Set motor speeds
	}
}


/* Drivetrain::SetSpeeds(int, int)
 * Inputs  - 
 * 		x-axis  (range 1 to -1)
 * 		y-axis (range 1 to -1)
 * Returns - 
 * 		None
 * 
 * Sets PWM rate corresponding to motor. If the
 * value is out of range, then the motors will
 * be stoped.
*/
void Drivetrain::ArcadeDrive(double x, double y) {
	bool Error = false;
	Error |= (x < -1 || x > -1);  // Check if left joystick is in range
	Error |= (y < -1 || y > -1);  // Check if right joystick is in range
	
	if (Error) {
		this->Stop();
	}
	else {
		double motor_l = minz(maxz((x+y),-1), 1);
		double motor_r = minz(maxz((x-y),-1), 1);
		this->SetSpeeds(motor_l, motor_r);
	}
}


/* Drivetrain::Stop()
 * Inputs  - 
 * 		None
 * Returns - 
 * 		None
 * 
 * Stops both motors
*/
void Drivetrain::Stop() {
	this->SetSpeeds(0.0, 0.0);
}


/* Drivetrain::SetInvert(bool, bool)
 * Inputs  - 
 * 		bool left side
 * 		bool right side
 * Returns - 
 * 		None
 * 
 * Sets inversion values for motors and 
 * stops both motors.
*/
void Drivetrain::SetInvert(bool l, bool r) {
	_Inverse_L = l;                 // Set left motor inverse
	_Inverse_R = r;                 // Set right motor inverse
	this->Stop();                    // Stop motors
}



/* Drivetrain::min(double)
 * Inputs  - 
 * 		double i
 * 		double n
 * Returns - 
 * 		None
 * 
 * Returns the smallest value
*/
double Drivetrain::minz(double i, double n) {
	return(i<n?i:n);
}


/* Drivetrain::max(double)
 * Inputs  - 
 * 		double i
 * 		double n
 * Returns - 
 * 		None
 * 
 * Returns the largest value
*/
double Drivetrain::maxz(double i, double n) {
	return(i>n?i:n);
}
