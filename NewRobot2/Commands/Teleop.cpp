#include "Teleop.h"

/* Teleop::Teleop()
 * Input   -
 * 	 None
 * Returns -
 *   None
 * 
 * Description -
 *   Grabs all subsystems required for teleop
 */
Teleop::Teleop() {
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	Requires(intake);
	Requires(kicker);
	Requires(platform);
	Requires(vision);
}




/* Teleop::Initialize()
 * Input   -
 * 	 None
 * Returns -
 *   None
 * 
 * Description -
 *   Initializes the teleop command
 */
void Teleop::Initialize() {
	kicker_speed = 0.00;
}




/* Teleop::Execute()
 * Input   -
 * 	 None
 * Returns -
 *   None
 * 
 * Description -
 *   Runs teleop periodically (usually every 50ms)
 */
void Teleop::Execute() {
	//*************** Grab operator interface data ***************//
	// Grab drive joysticks
	Joystick *left_driver_1   = oi->getJoystick1();
	Joystick *right_driver_1  = oi->getJoystick2();
	
	// Grab copilot joysticks
	//Joystick *left_driver_2   = oi->getJoystick3();
	//Joystick *right_driver_2  = oi->getJoystick4();
	
	// Grab shifter controller button(s)
	Button *shifter_btn       = oi->getShifterBtn();
	
	// Grab kicker controller button(s)
	Button *reload_btn        = oi->getReloadBtn();
	Button *kick_btn          = oi->getKickBtn();
	
	// Grab intake controller button(s)
	Button *intake_engage_btn = oi->getIntakeEngageBtn();
	
	// Grab platform control button(s)
	Button *platform_up_btn   = oi->getPlatformUpBtn();
	Button *platform_down_btn = oi->getPlatformDownBtn();
	
	//Get Vision Data
	vision->get_DS_Distance();
	
	
	//*************** Move Chassis Motors ************************//
	chassis->tankDrive(left_driver_1->GetY(), right_driver_1->GetY());
	
	//*************** Move Chassis Shifter ***********************//
	chassis->setShifter(shifter_btn->Get());
	
	
	
	
	//*************** Move Kicker Arm ****************************//
	double MaxKickerFwdSpd = 0.75;
	double MaxKickerRvsSpd = -0.40;
	
	if (kick_btn->Get() && !reload_btn->Get()) {
		// Kick Kicker Arm
		kicker->setSpeed(kicker_speed);
				
		if (kicker_speed>=MaxKickerFwdSpd) {
			kicker_speed=MaxKickerFwdSpd;
		}		
		else {
			kicker_speed += .055;
		}
	}
	else if (!kick_btn->Get() && reload_btn->Get()) {
		// Reload Kicker Arm
		kicker->setSpeed(kicker_speed);
				
		if (kicker_speed<=MaxKickerRvsSpd) {
			kicker_speed=MaxKickerRvsSpd;
		}		
		else {
			kicker_speed -= .055;
		}
	}
	else {
		// Stop Kicker Arm
		kicker_speed = 0.00;
		kicker->setSpeed(0.00);
	}
	
	
	
	
	
	//*************** Move Intake Arm and Motors *****************//
	if (intake_engage_btn->Get()){
		// Move intake arm down and spin motors
		intake->MoveSolenoid(true);
		intake->Set(0.50);
	}
	else {
		// Move intake arm up and stop motors
		intake->MoveSolenoid(false);
		intake->Set(0.00);
	}
	
	
	
	
	//*************** Move Platform ******************************//
	if (platform_up_btn->Get() && !platform_down_btn->Get()){
		// move platform up
		platform->setSpeed(0.10);
	}
	else if (!platform_up_btn->Get() && platform_down_btn->Get()){
		// move platform down
		platform->setSpeed(-0.10);
	}
	else {
		// Stop Platform
		platform->setSpeed(0.00);
	}
	
}




/* Teleop::IsFinished()
 * Input   -
 * 	 None
 * Returns -
 *   false
 * 
 * Description -
 *   returns false to cause the command to
 *   be placed on the scedular again
 */
bool Teleop::IsFinished() {
	return false;
}

/* Teleop::End()
 * Input   -
 * 	 None
 * Returns -
 *   None
 * 
 * Description -
 *   should never run
 */
void Teleop::End() {
	chassis->tankDrive(0.00, 0.00);
	kicker->setSpeed(0.00);
	intake->MoveSolenoid(false);
	intake->Set(0.00);
	platform->setSpeed(0.00);
}

/* Teleop::Interrupted()
 * Input   -
 * 	 None
 * Returns -
 *   None
 * 
 * Description -
 *   runs if teleop is interrupted
 */
void Teleop::Interrupted() {
	chassis->tankDrive(0.00, 0.00);
	kicker->setSpeed(0.00);
	intake->MoveSolenoid(false);
	intake->Set(0.00);
	platform->setSpeed(0.00);
}
