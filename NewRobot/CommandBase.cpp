#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize Operator Interface to NULL
OI*      CommandBase::oi      = NULL;

// Initialize single static instance of all of subsystems (set to NULL)
Chassis* CommandBase::chassis = NULL;
Kicker*  CommandBase::kicker  = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
Intake* CommandBase::intake = NULL;

/* CommandBase::init()
 * Inputs  -
 * 	None
 * Returns -
 *  None
 *  
 *  Create a single static instance of all of subsystems
*/
void CommandBase::init() {
	// Initialize operator interface
	oi = new OI();
	
	// Initialize subsystems
	chassis = new Chassis();
	kicker  = new Kicker();
	aircompressor = new AirCompressor();
	intake = new Intake();
}
