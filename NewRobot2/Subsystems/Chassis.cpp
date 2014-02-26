#include "Chassis.h"
#include "../Robotmap.h"


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
	
#if (USE_DISTANCE_PER_PULSE == 1)
	left_encode->SetDistancePerPulse((1/3)*(0.0001));
#endif
	
	right_encode  = new Encoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, false);
	right_encode->Start();
	
#if (USE_DISTANCE_PER_PULSE == 1)
	right_encode->SetDistancePerPulse((1/3)*(0.0001));
#endif
	
	gyro_sens     = new Gyro(GYRO_SENS);
	
	shifter       = new DoubleSolenoid(SHIFTER_A, SHIFTER_B);
	
#if (USE_DISTANCE_PER_PULSE == 1)
	distance_last = 0;
	
	Pi = acos(-1);
#else
	Pi = 4.0 * atan(1.0);
#endif
	
	left_encode->SetDistancePerPulse(.48/1440);
	right_encode->SetDistancePerPulse(.48/1440);
	
	SmartDashboard::PutNumber(SD_ENCODER_L_SPEED, left_encode->GetRate());
	SmartDashboard::PutNumber(SD_ENCODER_R_SPEED, right_encode->GetRate());
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

	SmartDashboard::PutNumber(SD_ENCODER_L_SPEED, left_encode->GetRate());
	SmartDashboard::PutNumber(SD_ENCODER_R_SPEED, right_encode->GetRate());
#if (USE_DISTANCE_PER_PULSE == 1)
	
	cout<<"Left Encoder: "<<left_encode->Get()<<"\t\tRight  Encoder: "<<right_encode->Get();
	
	left_encode->GetRate();
	
	
	double distance = ((((left_encode->Get()/1440)*.48)+((right_encode->Get()/1440)*.48))/2);
	
	double velocity = (distance-distance_last)/distance_clk->Get();
	
	SmartDashboard::PutNumber("RobotVelocity", velocity);
	
	distance_last = distance;
	distance_clk->Reset();
#endif
}


void Chassis::tankCosDrive(double left, double right) {
#if (USE_DISTANCE_PER_PULSE == 1)
	double motor_l = (( sin( left  * Pi - (Pi / 2) ) / 2) + ( 1 / 2));// * (left  < 0 ? -1 : 1);
	double motor_r = (( sin( right * Pi - (Pi / 2) ) / 2) + ( 1 / 2));// * (right < 0 ? -1 : 1);
	cout<<motor_l<<"\t\t"<<motor_r<<"\n";
#else
	double motor_l = (left  < 0 ? -1 : 1) * ( sin( left  * Pi - (Pi / 2) ) / 2) + ( 1 / 2);
	double motor_r = (right < 0 ? -1 : 1) * ( sin( right * Pi - (Pi / 2) ) / 2) + ( 1 / 2);
#endif	

	this->tankDrive(motor_l, motor_r);
}


#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
/*Chassis::arcadeDrive(Joystick*)
 * Inputs  -
 * 	joystick (Joystick*)
 * Returns -
 * 	None
 * 
 * Changes the motor speeds to given
 * parameters. Uses a curve (x^3 in 
 * calculations).
*/
void Chassis::arcadeDrive(double x, double y){
	x = (x*x*x);
	y = (y*y*y);
	
	double left  = y + x;
	double right = y - x;
	
	if (left >= 1) {
		left = 1;
	}
	if (left <= -1) {
		left = -1;
	}
	if (right >= 1) {
		right = 1;
	}
	if (right <= -1) {
		right = -1;
	}
	
	
	drive_left_1->Set(left);
	drive_left_2->Set(left);
	drive_right_1->Set(right*-1);
	drive_right_2->Set(right*-1);
}
#endif // #if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	


///Chassis::encoderReset()
///
///@brief This function zeros the encoder.
///
void Chassis::encoderReset() {
	left_encode->Reset();
	right_encode->Reset();
}


double Chassis::encoderLeftGet() {
	return left_encode->Get();
}

double Chassis::encoderRightGet() {
	return right_encode->Get();
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
