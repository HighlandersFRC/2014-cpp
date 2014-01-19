#include "Chassis.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoystick.h"
#include "../DebugPrint.h"


///Chassis::Chassis()
///
///@brief This function constructs the subsystem.
///
///This function does not take or return a value.
///
Chassis::Chassis() : Subsystem("Chassis") {
	drive_left_1  = new Talon(LEFT_DRIVE_MOTOR_1);
	drive_left_2  = new Talon(LEFT_DRIVE_MOTOR_2);
	drive_right_1 = new Talon(RIGHT_DRIVE_MOTOR_1);
	drive_right_2 = new Talon(RIGHT_DRIVE_MOTOR_2);
	
	left_encode   = new Encoder(LEFT_ENCODER_A, LEFT_ENCODER_B, false);
	left_encode->Start();
	
	dist_sens_1   = new AnalogChannel(DIST_SENS);
	
	gyro_sens     = new Gyro(1);
	
	shifter       = new DoubleSolenoid(SHIFTER_A, SHIFTER_B);
	
	compressoa    = new Compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY);
}


/*Chassis::InitDefaultCommand()
 * Inputs  -
 * 	None
 * Returns -
 * 	None
 * 
 * Sets default command for Chassis 
 * subsystem.
*/
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
	
	DebugPrint(1, "Setting Default Command for Chassis");
}


///Chassis::tankDrive(double, double)
///
///@brief This function moves the chassis based on y joystick axis position.
///
///@param left  : double argument for left joystick y-axis (range 1 to -1)
///@param right : double argument for right joystick y-axis (range 1 to -1)
///
///This function does not return a value.
///
void Chassis::tankDrive(double left, double right){
	drive_left_1->Set(left);
	drive_left_2->Set(left);
	drive_right_1->Set(right*-1);
	drive_right_2->Set(right*-1);
	//DebugPrint(0, "tankDrive!");
}


/*Chassis::arcadeDrive(Joystick*)
 * Inputs  -
 * 	joystick (Joystick*)
 * Returns -
 * 	None
 * 
 * Changes the motor speeds to given
 * parameters.
*/
void Chassis::arcadeDrive(Joystick* stick){
	//This should never be called!
	// We will never use Arcade drive!
}


///Chassis::getDistSens()
///
///@brief This function moves the chassis based on y joystick axis position.
///
///@param left  : double argument for left joystick y-axis (range 1 to -1)
///@param right : double argument for right joystick y-axis (range 1 to -1)
///
///This function returns a distance in inches as a double.
///
double Chassis::getDistSens() {
	return ((dist_sens_1->GetAverageVoltage()/5)*254);
}


///Chassis::encoderReset()
///
///@brief This function zeros the encoder.
///
void Chassis::encoderReset() {
	left_encode->Reset();
}


double Chassis::encoderGet() {
	return left_encode->Get();
}


///Chassis::getAngle()
///
///This function returns the angle measured by the gyro as a double.
///
double Chassis::getAngle() {
	return gyro_sens->GetAngle();
}

///Chassis::GyroReset()
///
///This function zeroes the gyroscope.
///
void Chassis::gyroReset() {
	gyro_sens->Reset();
}


void Chassis::setShifter(bool pos){
	if (pos) {
		shifter->Set(shifter->kForward);
	}
	else {
		shifter->Set(shifter->kReverse);
	}
}

void Chassis::tankExpDrive(double left, double right) {
	this->tankDrive(this->cube(left),this->cube(right));
}

double Chassis::cube(double n) {
	return (n*n*n);
}
