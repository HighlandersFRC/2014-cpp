#ifndef ROBOTMAP_H
#define ROBOTMAP_H


#define DRIVE_TYPE_TANK   0
#define DRIVE_TYPE_ARCADE 1

#define DRIVE_TYPE   DRIVE_TYPE_TANK




/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
*/

//      Name                   Number      Bus               Description                      Subsystem        User			Color
#define LEFT_DRIVE_MOTOR_1     1           // PWM Out        Left drive motor port 1          chassis          Zack			Yellow Green
#define LEFT_DRIVE_MOTOR_2     2           // PWM Out        Left drive motor port 2          chassis          Zack			Yellow Blue
#define RIGHT_DRIVE_MOTOR_1    3           // PWM Out        Right drive motor port 1         chassis          Zack			Red Green
#define RIGHT_DRIVE_MOTOR_2    4           // PWM Out        Right drive motor port 2         chassis          Zack			Red Blue
#define LEFT_ENCODER_A         2           // I/O            Left Encoder data A port         chassis          Zack			
#define LEFT_ENCODER_B         3           // I/O            Left Encoder data B port         chassis          Zack
#define RIGHT_ENCODER_A		   4           // I/O			 Right Encoder data A port	      chassis		   Drew
#define RIGHT_ENCODER_B		   5           // I/O			 Right Encoder data B port	      chassis		   Drew
#define DIST_SENS              2           // Analog in      Front Distance Sensor            vision           Zack			
#define GYRO_SENS              4           // Analog in      gyro for direction               chassis          Linda		
#define SHIFTER_A              1           // Pneumatic      forward gear shifter             chassis          Zack			
#define SHIFTER_B              2           // Pneumatic      reverse gear shifter             chassis          Zack			

#define COMPRESSOR_RELAY       2           // Relay          compressor motor relay           compressor       Drew			
#define COMPRESSOR_SWITCH      1           // I/O            compressor limit switch          compressor       Drew			
                                                                                                               
#define KICKER_MOTOR_1         5           // PWM Out        Kicker Motor 1                   kicker           Linda		White Yellow
#define KICKER_MOTOR_2         6           // PWM Out        Kicker Motor 2                   kicker           Linda		White Red
                                                                                                               
#define BELT_MOTOR             8           // PWM Out        elevation control for elevator   elevator         Zack			White Blue
#define BELT_POT               1           // Analog in      Pot for Belt position            elevator         Zack
                                                                                                               
#define INTAKE_MOTOR           7           // PWM Out        ball grab motor                  intake           Drew			White Green

#define SOL_A				   3		   // Pneumatic		 forward solenoid for intake	  nomos			   Drew			
#define SOL_B				   4		   // Pneumatic		 reverse solenoid for intake	  nomos			   Drew			


//***************************** Joystick Controls *****************************//
// Controllers
//         Name                Controller Number
const int JOYSTICK_PORT1     = 1;
const int JOYSTICK_PORT2     = 2;
const int JOYSTICK_PORT3     = 3;
const int JOYSTICK_PORT4     = 4;

// Buttons
//        Name                 Button Number         Controller Number
const int KICK_BTN		     = 1;                    // JOYSTICK_PORT2
const int RELOAD_BTN         = 2;                    // JOYSTICK_PORT2

const int SHIFTER_BTN        = 2;                    // JOYSTICK_PORT1

const int INTAKE_ENGAGE_BTN  = 1;					 // JOYSTICK_PORT1

const int PLATFORM_UP_BTN    = 8;                    // JOYSTICK_PORT1
const int PLATFORM_DOWN_BTN  = 9;                    // JOYSTICK_PORT1

#endif
