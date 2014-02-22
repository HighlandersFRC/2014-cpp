#include "Teleop.h"
#include "..\Joystickmap.h"

#define LINDA_NEW 1

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
	kick_press = false;
	SmartDashboard::PutNumber("Kicker_Speed_Forward", 1.0);
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
	chassis->tankDrive(-oi->getAxisRightDrive(DRIVE_R), -oi->getAxisLeftDrive(DRIVE_L));
#endif
	
	//cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight Encoder: "<<chassis->encoderRightGet()<<"\n";
	
	
	//*************** Move Chassis Shifter ***********************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->setShifter(!right_driver_1->GetRawButton(6));
#else
	chassis->setShifter(!oi->getBtn(SHIFT));
#endif
	
	
	//*************** Move Kicker Arm ****************************//
	
	//double MaxKickerFwdSpd = -1*((oi->getAxis(KICKER_POWER)/2)-0.5);
	//cout<<MaxKickerFwdSpd<<"\n";	
	//int Max_time = (int)SmartDashboard::GetNumber("Kicker Time");
	
	//manual joystick kick
	if (oi->getBtn(MANUAL_KICK)) {
		kick_press = false;
		kicker->setSpeed(-oi->getAxisCopilotRight(KICKER_MAN_C));
		kicker_timer->Stop();
		kicker_timer->Reset();
	}
	//button kick
	else if (oi->getBtn(KICK)) {
		kick_press = true;
		kicker_timer->Reset();
	}
	else if (!kick_press){
		// Stop Kicker Arm
		kicker->setSpeed(0.00);
	}
	
	//auto-kicker sequence
	if(kick_press) {
		kicker_timer->Start();
		
		if(kicker_timer->Get() <= 0.4) {
			kicker->setSpeed(-0.5);
		} else if(kicker_timer->Get() <= 0.6) {
			intake->MoveSolenoid(true);
			intake->Set(-0.5);
		} else if(kicker_timer->Get() <= 0.8) {
			intake->Set(0.0);
		} else {
			kicker_timer->Stop();
			kicker_timer->Reset();
			kick_press = false;
		}
//		else if(kicker_timer->Get() > 0.4 && kicker_timer->Get() <= 1.6) {
//			kicker->setSpeed(0.0);
//		}
//		else if(kicker_timer->Get() > 1.6 && kicker_timer->Get() <= 2.0) {
//			kicker->setSpeed(1.0);
//		}
//		else {
//			kicker_timer->Stop();
//			kick_press = false;
//		}
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

	
#if LINDA_NEW	
	//Intake Sequence: "lower arm + wheels in + platform down, then platform up."
	if(oi->getBtn(INTAKE_SEQUENCE)){
//		if (intake_sequence_pressed == false){
			intake->MoveSolenoid(true);
			intake->Set(-1.00);
			platform->SetSetpoint(0.0);
			intake_sequence_pressed = true;
//		}
	}
	else if(intake_sequence_pressed && !oi->getBtn(INTAKE_SEQUENCE)){
		intake_sequence_pressed = false;
		intake->MoveSolenoid(false);
		intake->Set(0.00);
	}
#endif	
	
#endif
	
	
	//*************** Move platform ******************************//
	
	//manual platform movement
	if ((oi->getAxisCopilotLeft(PLATFORM_C) <= 0.1 ) && (oi->getAxisCopilotLeft(PLATFORM_C) >= -0.1 )) {
		if (!PID_enable) {
			platform->setSpeed(0.00);
		}
	} else {
		platform->Disable();
		PID_enable = false;
		platform->setSpeed(-oi->getAxisCopilotLeft(PLATFORM_C));
	}
	
	//pre-set platform movement buttons
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
		platform->SetSetpoint(2.0);
	} else if(oi->getBtn(PLATFORM_KICK_POS4)) {
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(0.0);
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
	pos = 0;
	PID_enable = true;
	kick_press = false;
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
	kick_press = false;
}
