#include "WPILib.h"
#include "Robotmap.h"			// for: SD_KICKER_NEXT_SPEED
#include "DebugPrint.h"			// for: DebugPrint()
#include "CommandBase.h"		// for all subsystems.
#include "Commands/Scheduler.h"


// Initialize Operator Interface to NULL
OI* CommandBase::oi = NULL;

// Initialize single static instance of all of subsystems (set to NULL)
Chassis*       CommandBase::chassis       = NULL;
Kicker*        CommandBase::kicker        = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
Intake*        CommandBase::intake        = NULL;
Vision*        CommandBase::vision        = NULL;
Platform*      CommandBase::platform      = NULL;
LiveWindow*    CommandBase::lw            = NULL;


CommandBase::CommandBase(const char *name) : Command(name) 
{
}


CommandBase::CommandBase() : Command() 
{
}


/* CommandBase::init()
 * Inputs  -
 * 	None
 * Returns -
 *  None
 *  
 *  Create a single static instance of all of subsystems
*/
void CommandBase::init() 
{
	// Initialze SmartDashboard Values 
	//   Numeric Values:
	SmartDashboard::PutNumber(SD_KICKER_CURRENT_SPEED,       0);
	SmartDashboard::PutNumber(SD_DISTANCE,                   0);
	SmartDashboard::PutNumber(SD_PLATFORM_POS,               0);
	SmartDashboard::PutNumber(SD_KICK_SPEED_FWD,             1.0);
	SmartDashboard::PutNumber(SD_PREP_KICK_PLAT_HEIGHT,      2.3);
	SmartDashboard::PutNumber(SD_DRIVE_ENCODER_L_SPEED,      0);
	SmartDashboard::PutNumber(SD_DRIVE_ENCODER_R_SPEED,      0);
	SmartDashboard::PutNumber(SD_DRIVE_ENCODER_L_VAL,        0);
	SmartDashboard::PutNumber(SD_DRIVE_ENCODER_R_VAL,        0);

	//   Debug string values
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_3, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_2, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_1, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST, 		   "--------------------------------------------------------");
	
	//   multi-value string
	SmartDashboard::PutString(SD_INTAKE_ARM_POS,    SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_COMPRESSOR,        SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_PLATFORM_LOCATION, SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_INTAKE_WHEELS_DIR, SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_CHASSIS_SHIFTER,   SD_STRING_UNKNOWN);

	lw = LiveWindow::GetInstance();
	
	// Initialize operator interface
	DebugPrint(DBG_PRT_V1, "calling: new OI()");
	oi = new OI();
	
	// Create subsystems
	chassis       = new Chassis();
	kicker        = new Kicker();
	aircompressor = new AirCompressor();
	intake        = new Intake();
	platform      = new Platform();
	vision        = new Vision();
	
	// Display the status of the scheduler
	SmartDashboard::PutData(Scheduler::GetInstance());
}
