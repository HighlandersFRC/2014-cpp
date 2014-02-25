#include "WPILib.h"
#include "Robotmap.h"			// for: SD_KICKER_NEXT_SPEED
#include "DebugPrint.h"			// for: DebugPrint()
#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize Operator Interface to NULL
OI* CommandBase::oi = NULL;

// Initialize single static instance of all of subsystems (set to NULL)
Chassis*       CommandBase::chassis       = NULL;
Kicker*        CommandBase::kicker        = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
Intake*        CommandBase::intake        = NULL;
Platform*      CommandBase::platform      = NULL;
Vision*        CommandBase::vision        = NULL;

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
	SmartDashboard::PutNumber(SD_KICKER_NEXT_SPEED, 0);
	SmartDashboard::PutNumber(SD_KICKER_CURRENT_SPEED, 0);
	SmartDashboard::PutNumber(SD_DISTANCE, 0);
	SmartDashboard::PutNumber(SD_PLATFORM_PID_POS, 0);
	SmartDashboard::PutNumber(SD_INTAKE_WHEELS_SPEED, 0);
	SmartDashboard::PutNumber(SD_KICK_SPEED_FWD, 1.0);
	SmartDashboard::PutNumber(SD_PREP_KICK_THRESHOLD_HEIGHT, 2.8);
	SmartDashboard::PutNumber(SD_PREP_KICK_PLAT_HEIGHT, 2.3);

	//   Debug string values
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_3, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_2, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST_MINUS_1, "--------------------------------------------------------");
	SmartDashboard::PutString(SD_DBG_PRT_LAST, 		   "--------------------------------------------------------");
	
	//   multi-value string
	SmartDashboard::PutString(SD_INTAKE_ARM_POS,    SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_COMPRESSOR_ON_OFF, SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_PLATFORM_LOCATION, SD_STRING_UNKNOWN);
	SmartDashboard::PutString(SD_INTAKE_WHEELS_DIR, SD_STRING_UNKNOWN);


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
