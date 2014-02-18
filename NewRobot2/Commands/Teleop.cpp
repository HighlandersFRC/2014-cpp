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
//	SmartDashboard::PutNumber("P Value: ", 1.0); 
//	SmartDashboard::PutNumber("I Value: ", 0.0);
//	SmartDashboard::PutNumber("D Value: ", 0.0);
	platform->SetSetpoint(1.0);
	pos = 0;
	PID_enable = true;
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
	//*************** Get Vision Data ****************************//
	vision->get_DS_Distance();
	
	
	//*************** Move Chassis Motors ************************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->arcadeDrive(-driver_1->GetRawAxis(1), -driver_1->GetRawAxis(2));
#else
	chassis->tankDrive(-oi->getAxis(DRIVE_R), -oi->getAxis(DRIVE_L));
#endif
		
	
	cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight Encoder: "<<chassis->encoderRightGet()<<"\n";
	
	
	//*************** Move Chassis Shifter ***********************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->setShifter(!right_driver_1->GetRawButton(6));
#else
	chassis->setShifter(!oi->getBtn(SHIFT));
#endif
	
	
	//*************** Move Kicker Arm ****************************//
	double MaxKickerFwdSpd = -1*((oi->getAxis(KICKER_POWER)/2)-0.5);
	cout<<MaxKickerFwdSpd<<"\n";
	
	int Max_time = (int)SmartDashboard::GetNumber("Kicker Time");
	
	if (oi->getBtn(MANUAL_KICK)) {
		kicker->setSpeed(-oi->getAxis(KICKER_MAN_C));
		kicker_timer->Reset();
	}
	else if (oi->getBtn(KICK)) {
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
	if (oi->getBtn(INTAKE_IN)) {
		intake->Set(-1.00);
	}
	else if (oi->getBtn(INTAKE_OUT)) {
		intake->Set(1.00);
	}
	else {
		intake->Set(0.00);
	}
	
	if(oi->getBtn(INTAKE_SOL_IN)){
		intake->MoveSolenoid(false);
	} else if(oi->getBtn(INTAKE_SOL_OUT)) {
		intake->MoveSolenoid(true);
	}
	//intake->MoveSolenoid(oi->getBtn(INTAKE_SOL));
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
	
	
	
	//platform->setPIDValue(SmartDashboard::GetNumber("P Value: "), SmartDashboard::GetNumber("I Value: "), SmartDashboard::GetNumber("D Value: "));
	
	if ((oi->getAxis(PLATFORM_C) <= 0.1 ) && (oi->getAxis(PLATFORM_C) >= -0.1 )) {
		if (!PID_enable) {
			platform->setSpeed(0.00);
		}
	} else {
		platform->Disable();
		PID_enable = false;
		platform->setSpeed(-oi->getAxis(PLATFORM_C));
	}
	
	//cout<<"Voltage: "<<platform->ReturnPIDInput();
	
	if(oi->getBtn(PLATFORM_KICK_POS1)) {
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(3.0);
	} else if(oi->getBtn(PLATFORM_KICK_POS2)) {
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(0.5);
	} else if(oi->getBtn(PLATFORM_KICK_POS3)) {
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(0.0);
	} else if(oi->getBtn(PLATFORM_KICK_POS4)) {
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(0.0);
	}
	
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
	pos = 0;
	PID_enable = true;
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
	pos = 0;
	PID_enable = true;
}
