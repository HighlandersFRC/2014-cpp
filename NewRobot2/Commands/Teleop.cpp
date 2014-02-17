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
	
	// Init Timer for kicker
	kicker_timer = new Timer();
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
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	Joystick *driver_1        = oi->getJoystick1();
#endif	
	Joystick *left_driver_1   = oi->getJoystick1();
	Joystick *right_driver_1  = oi->getJoystick2();
	
	// Grab copilot joysticks
	Joystick *left_driver_2   = oi->getJoystick3();
	Joystick *right_driver_2  = oi->getJoystick4();
	
//	// Grab shifter controller button(s)
//	Button *shifter_btn       = oi->getShifterBtn();
//	
//	// Grab kicker controller button(s)
//	Button *reload_btn        = oi->getReloadBtn();
//	Button *kick_btn          = oi->getKickBtn();
//	
//	// Grab intake controller button(s)
//	Button *intake_engage_btn = oi->getIntakeEngageBtn();
//	
//	// Grab platform control button(s)
//	Button *platform_up_btn   = oi->getPlatformUpBtn();
//	Button *platform_down_btn = oi->getPlatformDownBtn();
	
	//Get Vision Data
	vision->get_DS_Distance();
	
	
	//*************** Move Chassis Motors ************************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->arcadeDrive(-driver_1->GetRawAxis(1), -driver_1->GetRawAxis(2));
#else
	chassis->tankDrive(-right_driver_1->GetY(), -left_driver_1->GetY());
#endif
		
	
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight Encoder: "<<chassis->encoderRightGet()<<"\n";
	
	
	//*************** Move Chassis Shifter ***********************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->setShifter(!right_driver_1->GetRawButton(6));
#else
	chassis->setShifter(!right_driver_1->GetRawButton(2));
#endif
	
	
	//*************** Move Kicker Arm ****************************//
	double MaxKickerFwdSpd = -1*((right_driver_2->GetRawAxis(4)/2)-0.5);
	cout<<MaxKickerFwdSpd<<"\n";
	
	int Max_time = (int)SmartDashboard::GetNumber("Kicker Time");
	
	if (right_driver_2->GetRawButton(2)) {
		kicker->setSpeed(right_driver_2->GetY());
		kicker_timer->Reset();
	}
	else if (right_driver_2->GetRawButton(1)) {
		if (kicker_timer->Get() <= Max_time) {
			kicker->setSpeed(MaxKickerFwdSpd);
		}
		else {
			kicker->setSpeed(0.00);
		}
	}
	else {
		// Stop Kicker Arm
		kicker->setSpeed(0.00);
		kicker_timer->Reset();
	}
	
	
	
	
	
	//*************** Move Intake Arm and Motors *****************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	if (driver_1->GetRawButton(5)) {
		intake->Set(-1.00);
	}
	else if (driver_1->GetRawButton(7)) {
		intake->Set(1.00);
	}
	else {
		intake->Set(0.00);
	}
	
	intake->MoveSolenoid(left_driver_1->GetRawButton(8));
#else
	if (left_driver_2->GetRawButton(7)) {
		intake->Set(-1.00);
	}
	else if (left_driver_2->GetRawButton(6)) {
		intake->Set(1.00);
	}
	else {
		intake->Set(0.00);
	}
	
	intake->MoveSolenoid(left_driver_1->GetRawButton(2));
#endif
	
//	if (intake_engage_btn->Get()){
//		// Move intake arm down and spin motors
//		intake->MoveSolenoid(true);
//		intake->Set(-1.00);
//	}
//	else {
//		// Move intake arm up and stop motors
//		intake->MoveSolenoid(false);
//		intake->Set(0.00);
//	}
	
	
	
	
	//*************** Move platform ******************************//
	if (!left_driver_2->GetRawButton(1)) {
		platform->setSpeed(-left_driver_2->GetY());
	}
	else {
		//platform->SetSetpoint(.5);
	}
	
	cout<<"Voltage: "<<platform->ReturnPIDInput();
	//
/*
	if(right_driver_2->GetRawButton(3) == true) {
		platpres = true;
		wantedheight = 0;				//PRESET 1: Floor
			}
	//TODO THIS IS CURRENTLY A THROWAWAY VALUE. FIX IT WHEN YOU KNOW VALUE.
	else if(right_driver_2->GetRawButton(4) == true) {
		platpres = true;
		wantedheight = 3;				//PRESET 2: Min Height
	}
	else if(right_driver_2->GetRawButton(5) == true) {
		platpres = true;
		wantedheight = 1.68;			//PRESET 3: 1.68 Volts
	}
	//TODO THIS IS CURRENTLY A THROWAWAY VALUE. FIX IT WHEN YOU KNOW VALUE.
	else if(right_driver_2->GetRawButton(6) == true) {
		platpres = true;
		wantedheight = 3;				//PRESET 4: 1 More Value
	}

	
	if (left_driver_2->GetY() >= .25 || left_driver_2->GetY() <= -.25) {
		platpres = false;
	}
	
	if (platpres == true) {
		platform->requestPosition(wantedheight);
	}
*/
	
	
	//	if (platform_up_btn->Get() && !platform_down_btn->Get()){
//		// move platform up
//		platform->setSpeed(0.50);
//	}
//	else if (!platform_up_btn->Get() && platform_down_btn->Get()){
//		// move platform down
//		platform->setSpeed(-0.50);
//	}
//	else {
//		// Stop platform
//		platform->setSpeed(0.00);
//	}
	

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
