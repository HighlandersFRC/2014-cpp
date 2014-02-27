#include "WPILib.h"
#include "..\Robotmap.h"		    // for: SD_PREP_KICK_PLAT_HEIGHT
#include "..\DebugPrint.h"			// for: DebugPrint()
#include "..\Joystickmap.h"			// for: DRIVE_R
#include "Teleop.h"


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
Teleop::Teleop() 
{
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
void Teleop::Initialize() 
{
	DebugPrint(DBG_PRT_V1, "called: Teleop::Initialize()");
	
	// @todo: CLEAN 	SmartDashboard::PutNumber("P Value: ", 1.0); 
	// @todo: CLEAN 	SmartDashboard::PutNumber("I Value: ", 0.0);
	// @todo: CLEAN 	SmartDashboard::PutNumber("D Value: ", 0.0);
	
	platform->SetSetpoint(1.0);
	
	pos = 0;
	PID_enable = true;
	kick_prep = false;
	kick_ball = false;
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
void Teleop::Execute() 
{	
	// Display the status of the scheduler
	// @todo: CLEAN SmartDashboard::PutData(Scheduler::GetInstance());

	//*************** Get Vision Data ****************************//
	vision->get_DS_Distance();
	
	//*************** Move Chassis Motors ************************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->arcadeDrive(-driver_1->GetRawAxis(1), -driver_1->GetRawAxis(2));
#else
	chassis->tankDrive(-oi->getAxisRightDrive(DRIVE_R), -oi->getAxisLeftDrive(DRIVE_L));
#endif
	
	// @todo: CLEAN cout<<"Left Encoder: "<<chassis->encoderLeftGet()<<"\t\tRight Encoder: "<<chassis->encoderRightGet()<<"\n";
	
	
	//*************** Move Chassis Shifter ***********************//
#if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)	
	chassis->setShifter(!right_driver_1->GetRawButton(6));
#else
	chassis->setShifter(!oi->getBtn(SHIFT));
#endif
	
	//*************** Move Kicker Arm ****************************//
	
	// @todo: CLEAN double MaxKickerFwdSpd = -1*((oi->getAxis(KICKER_POWER)/2)-0.5);
	// @todo: CLEAN cout<<MaxKickerFwdSpd<<"\n";	
	// @todo: CLEAN int Max_time = (int)SmartDashboard::GetNumber("Kicker Time");
	
	// manual joystick kick
	
	if (oi->getBtn(MANUAL_KICK)) 
	{
		kick_prep = false;
		kick_ball = false;
		kicker->setSpeed(-oi->getAxisCopilotRight(KICKER_MAN_C));
		kicker_timer->Stop();
		kicker_timer->Reset();
		kicker_timer->Start();
	}
	else if (oi->getBtn(KICKER_PREP)) 
	{
		// button kick
		kick_prep = true;
		kicker_timer->Reset();
		kicker_timer->Start();
	}
	else if (oi->getBtn(KICK)) 
	{
		kick_ball = true;
		kicker_timer->Reset();
		kicker_timer->Start();
	}
	else if (!kick_prep && !kick_ball)
	{
		// Stop Kicker Arm
		kicker->setSpeed(0.00);
	}
	
	// AUTO-KICKER PREP SEQUENCE
	if (kick_prep) 
	{	
		if (kicker_timer->Get() <= 0.3) 
		{	
			// Moves kicker above ball to hold it for 0.4 seconds
			kicker->setSpeed(-0.5);
		} 
		else if (kicker_timer->Get() <= 0.8) 
		{
			intake->MoveSolenoid(true);		
			
			// Puts intake forward and moves wheels inward for 0.4 seconds
			kicker->setSpeed(0.0);
			intake->Set(-0.5);
			
			platform->Enable();			
			PID_enable = true;
						
			platform->SetSetpoint(SmartDashboard::GetNumber(SD_PREP_KICK_PLAT_HEIGHT));
		} 
		else if (!kick_ball) 
		{
			intake->Set(0.0);	
			
			// Stops intake wheels and sets SetPoint of platform to SD_PREP_KICK_PLAT_HEIGHT
			//platform->Enable();			
			//PID_enable = true;
			
			//platform->SetSetpoint(SmartDashboard::GetNumber(SD_PREP_KICK_PLAT_HEIGHT));
			
			// Grabs position (4 to 0) and divides it by 16 creating the range .125 to 0 then 
			// subtracting .125 creates the range .125 to -.125 finally inverting the 
			// range by multiplying by -1 
			kicker->setSpeed((platform->GetPosition()/16-.125)*-1);
		} 
		else 
		{
			kick_prep = false;
		}
	}
	
	// AUTO-KICKER KICK SEQUENCE
	if(kick_ball) 
	{
		
		if(kicker_timer->Get() <= 0.4) 
		{	
			// kicks ball for 0.4 seconds
			kicker->setSpeed(SmartDashboard::GetNumber(SD_KICK_SPEED_FWD));
		} 
		else 
		{
			platform->SetSetpoint(1.0);
			kick_ball = false;
		}
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
	if (oi->getBtn(INTAKE_IN)) 
	{
		intake->Set(-1.00);
	}
	else if (oi->getBtn(INTAKE_OUT)) 
	{
		intake->Set(1.00);
	}
	else 
	{
		intake->Set(0.00);
	}
	
	if(oi->getBtn(INTAKE_SOL_IN))
	{
		intake->MoveSolenoid(false);
	} 
	else if(oi->getBtn(INTAKE_SOL_OUT)) 
	{
		intake->MoveSolenoid(true);
	}
	
	// @todo: CLEAN intake->MoveSolenoid(oi->getBtn(INTAKE_SOL));

	
  #if LINDA_NEW	
	// Intake Sequence: "lower arm + wheels in + platform down, then platform up."
	if(oi->getBtn(INTAKE_SEQUENCE))
	{
		// @todo: CLEAN 		if (intake_sequence_pressed == false){
		intake->MoveSolenoid(true);
		intake->Set(-1.00);
		platform->SetSetpoint(0.0);
		intake_sequence_pressed = true;
		// @todo: CLEAN 		}
	}
	else if(intake_sequence_pressed && !oi->getBtn(INTAKE_SEQUENCE))
	{
		intake_sequence_pressed = false;
		intake->MoveSolenoid(false);
		intake->Set(0.00);
	}
  #endif // #if LINDA_NEW	
	
#endif // #if (DRIVE_TYPE == DRIVE_TYPE_ARCADE)
	
	
	//*************** Move platform ******************************//
	
	// manual platform movement
	if ((oi->getAxisCopilotLeft(PLATFORM_C) <= 0.1 ) && (oi->getAxisCopilotLeft(PLATFORM_C) >= -0.1 )) 
	{
		if (!PID_enable) 
		{
			platform->setSpeed(0.00);
		}
	} 
	else 
	{
		platform->Disable();
		PID_enable = false;
		//kick_prep = false;
		kick_ball = false;
		platform->setSpeed(-oi->getAxisCopilotLeft(PLATFORM_C));
	}
	
	// pre-set platform movement buttons
	if(oi->getBtn(PLATFORM_KICK_POS1)) 
	{
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(1.0);
	} 
	else if(oi->getBtn(PLATFORM_KICK_POS2)) 
	{
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(2.0);
	} 
	else if(oi->getBtn(PLATFORM_KICK_POS3)) 
	{
		platform->Enable();
		PID_enable = true;
		platform->SetSetpoint(3.0);
	}
	
	SmartDashboard::PutNumber(SD_PLATFORM_POS, platform->GetPosition());
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
bool Teleop::IsFinished() 
{
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
void Teleop::End() 
{
	DebugPrint(DBG_PRT_V1, "called: Teleop::End()");
	
	chassis->tankDrive(0.00, 0.00);
	kicker->setSpeed(0.00);
	intake->MoveSolenoid(false);
	intake->Set(0.00);
	platform->setSpeed(0.00);
	pos = 0;
	PID_enable = true;
	kick_prep = false;
	kick_ball = false;
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
void Teleop::Interrupted() 
{
	DebugPrint(DBG_PRT_V1, "called: Teleop::Interrupted()");

	chassis->tankDrive(0.00, 0.00);
	kicker->setSpeed(0.00);
	intake->MoveSolenoid(false);
	intake->Set(0.00); 
	platform->setSpeed(0.00);
	pos = 0;
	PID_enable = true;
	kick_prep  = false;
	kick_ball  = false;
}
