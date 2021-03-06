#ifndef ROBOTMAP_H
#define ROBOTMAP_H



/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
*/

//      Name                    Number  Bus                 Description                     Subsystem       User
#define LEFT_DRIVE_MOTOR_1		1		// PWM Out			Left drive motor port 1			chassis			Zack
#define LEFT_DRIVE_MOTOR_2		2		// PWM Out			Left drive motor port 2			chassis         Zack
#define RIGHT_DRIVE_MOTOR_1		3       // PWM Out			Right drive motor port 1		chassis         Zack
#define RIGHT_DRIVE_MOTOR_2		4       // PWM Out			Right drive motor port 2        chassis         Zack
#define LEFT_ENCODER_A			1       // I/O				Left Encoder data A port        chassis         Zack
#define LEFT_ENCODER_B			2       // I/O				Left Encoder data B port        chassis         Zack
#define DIST_SENS				3       // Analog in		Front Distance Sensor           sensors         Zack
#define GYRO_TEMP				2		// Analog in		Gyro Temperature sensor			sensors			Linda
#define GYRO_SENS				1       // Analog in		gyro for direction              sensors         Linda
#define SHIFTER_A				1       // Pneumatic		forward gear shifter            chassis         Zack
#define SHIFTER_B				2       // Pneumatic		reverse gear shifter            chassis         Zack

#define COMPRESSOR_RELAY		1       // Relay			compressor motor relay          compressor      Drew
#define COMPRESSOR_SWITCH		3       // I/O				compressor limit switch         compressor      Drew
                                                                                                               
#define KICKER_MOTOR_1			5       // PWM Out			Kicker Motor 1                  kicker			Linda
#define KICKER_MOTOR_2			6       // PWM Out			Kicker Motor 2                  kicker			Linda
                                                                                                               
#define BELT_MOTOR				8       // PWM Out			elevation control for platform	platform        Zack
#define BELT_ENCODER_A			4		// I/O				Elevator Encoder port A			platform		Linda
#define BELT_ENCODER_B			5		// I/O				Elevator Encoder port B			platform		Linda
                                                                                                               
#define INTAKE_MOTOR			7       // PWM Out			ball grab motor                 intake          Drew

#define SOL_A					3		// Pneumatic		forward solenoid for intake		nomos			Drew
#define SOL_B					4		// Pneumatic		reverse solenoid for intake		nomos			Drew


//***************************** Joystick Controls *****************************//
// Controllers
//         Name                Controller Number
const int JOYSTICK_PORT1     = 1;
const int JOYSTICK_PORT2     = 2;
const int JOYSTICK_PORT3     = 3;
const int JOYSTICK_PORT4     = 4;

// Buttons
//        Name                 Button Number         Controller Number
const int INTAKE_OUT_BTN     = 1;					 // JOYSTICK_PORT1
const int INTAKE_ELEVATE_DOWN =2;					 //	JOYSTICK_PORT1
const int INTAKE_ELEVATE_UP  = 3;					 // JOYSTICK_PORT1

const int INTAKE_IN_BTN		 = 1;					 // JOYSTICK_PORT2
const int SHIFT_DOWN_BTN     = 2;                    // JOYSTICK_PORT2
//const int SHIFT_UP_BTN       = 3;                    // JOYSTICK_PORT2

const int KICK_BTN           = 1;                    // JOYSTICK_PORT4
const int RELOAD_BTN         = 2;                    // JOYSTICK_PORT4


#endif
