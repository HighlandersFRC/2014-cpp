#ifndef ROBOTMAP_H
#define ROBOTMAP_H



/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
*/

//      Name					Number	   Bus				Description						Subsystem	User	Color
#define LEFT_DRIVE_MOTOR_1		1		// PWM Out			Left drive motor port 1         chassis     Zack	Yellow Green
#define LEFT_DRIVE_MOTOR_2      2		// PWM Out          Left drive motor port 2         chassis     Zack	Yellow Blue
#define RIGHT_DRIVE_MOTOR_1     3       // PWM Out          Right drive motor port 1        chassis     Zack	Red Green
#define RIGHT_DRIVE_MOTOR_2     4       // PWM Out          Right drive motor port 2        chassis     Zack	Red Blue
#define LEFT_ENCODER_A          2       // I/O              Left Encoder data A port        chassis     Zack			
#define LEFT_ENCODER_B          3       // I/O              Left Encoder data B port        chassis     Zack
#define RIGHT_ENCODER_A		    4       // I/O				Right Encoder data A port	    chassis		Drew
#define RIGHT_ENCODER_B		    5       // I/O				Right Encoder data B port	    chassis		Drew
#define GYRO_SENS               2       // Analog in      	gyro for direction              chassis     Linda
#define GYRO_TEMP               3       // Analog in        gyro temperature sensor         chassis     Linda
#define DIST_SENS               4       // Analog in		Front Distance Sensor           vision      Zack	
#define SHIFTER_A               1       // Pneumatic  	    forward gear shifter            chassis     Zack			
#define SHIFTER_B               2       // Pneumatic  	    reverse gear shifter            chassis     Zack			

#define COMPRESSOR_RELAY        1       // Relay			compressor motor relay          compressor  Drew			
#define COMPRESSOR_SWITCH       1       // I/O            	compressor limit switch         compressor  Drew			
                                                                                                               
#define KICKER_MOTOR_1          5       // PWM Out        	Kicker Motor 1                  kicker      Linda	White Yellow
#define KICKER_MOTOR_2          6       // PWM Out        	Kicker Motor 2                  kicker      Linda	White Red
                                                                                                               
#define BELT_MOTOR              8       // PWM Out        	elevation control for elevator  platform    Zack	White Blue
#define BELT_POT                1       // Analog in      	Pot for Belt position           platform    Zack
                                                                                                               
#define INTAKE_MOTOR            7       // PWM Out        	ball grab motor                 intake      Drew	White Green

#define SOL_A					3		// Pneumatic		forward solenoid for intake	  	nomos		Drew			
#define SOL_B					4		// Pneumatic		reverse solenoid for intake	  	nomos		Drew			

// SmartDashboard Values Key tokens:
//   Numeric Values:
#define SD_KICKER_NEXT_SPEED     		"Next Kick Speed"
#define SD_KICKER_CURRENT_SPEED  		"Current Kick Speed"
#define SD_DISTANCE              		"Distance in centimeters"
#define SD_PLATFORM_PID_POS      		"Platform PID Position"
#define SD_INTAKE_WHEELS_SPEED   		"Intake Wheel Speed"
#define SD_PREP_KICK_PLAT_HEIGHT     	"Prep Kick Platform Height"
#define SD_PREP_KICK_THRESHOLD_HEIGHT 	"Prep Kick Threshold Height"
#define SD_KICK_SPEED_FWD               "Kicker Speed Forward"
//   Debug string values
#define SD_DBG_PRT_DISPLAY_COUNT  4
#define SD_DBG_PRT_LAST          		"Debug print (last)"
#define SD_DBG_PRT_LAST_MINUS_1  		"Debug print (last-1)"
#define SD_DBG_PRT_LAST_MINUS_2  		"Debug print (last-2)"
#define SD_DBG_PRT_LAST_MINUS_3  		"Debug print (last-3)"
//   multi-value string
//     Intake arm: IN, OUT, UNKNOWN
#define SD_INTAKE_ARM_POS        		"Intake Arm Position"
//     Compressor: ON, OFF, UNKNOWN
#define SD_COMPRESSOR_ON_OFF     		"Compressor On/OFF"
//     Platform location: BOTTOM, LOW_KICK, HIGH_KICK, TOP, NONE
#define SD_PLATFORM_LOCATION     		"Platform Known Locations"
//     Intake Wheel Direction: IN, OUT, OFF, UNKNOWN
#define SD_INTAKE_WHEELS_DIR     		"Intake Wheels Spin Direction"
//     Chassis encoder values
#define SD_ENCODER_L_SPEED              "Left Motor Speed"
#define SD_ENCODER_R_SPEED              "Right Motor Speed"
// Generic String values for discreet settings:
  #define SD_STRING_ON       "ON"
  #define SD_STRING_OFF      "OFF"
  #define SD_STRING_IN       "IN"
  #define SD_STRING_OUT      "OUT"
  #define SD_STRING_UNKNOWN  "UNKNOWN"


#endif // #ifndef ROBOTMAP_H

