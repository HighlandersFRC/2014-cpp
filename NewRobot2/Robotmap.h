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




#endif
