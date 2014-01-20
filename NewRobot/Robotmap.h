#ifndef ROBOTMAP_H
#define ROBOTMAP_H



/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
*/

//      Name                   Number      Bus               Description                    Subsystem
#define LEFT_DRIVE_MOTOR_1     1           // PWM Out        Left drive motor port 1        chassis
#define LEFT_DRIVE_MOTOR_2     2           // PWM Out        Left drive motor port 2        chassis
#define RIGHT_DRIVE_MOTOR_1    3           // PWM Out        Right drive motor port 1       chassis
#define RIGHT_DRIVE_MOTOR_2    4           // PWM Out        Right drive motor port 2       chassis
#define LEFT_ENCODER_A         1           // I/O            Left Encoder data A port       chassis
#define LEFT_ENCODER_B         2           // I/O            Left Encoder data B port       chassis
#define DIST_SENS              2           // Analog in      Front Distance Sensor          chassis
#define GYRO_SENS              1           // Analog in      gyro for dirrection            chassis
#define SHIFTER_A              1           // Pneumatic      forward gear shifter           chassis
#define SHIFTER_B              2           // Pneumatic      reverse gear shifter           chassis
#define COMPRESSOR_RELAY       1           // Relay          compressor motor relay         chassis
#define COMPRESSOR_SWITCH      3           // I/O            compressor limit switch        chassis

#define KICKER_MOTOR_1         5           // PWM Out        Kicker Motor 1                 kicker
#define KICKER_MOTOR_2         6           // PWM Out        Kicker Motor 2                 kicker

#define INTAKE_MOTOR		   7		   // PWM Out		 Intake Motor					intake


#endif
