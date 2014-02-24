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
void CommandBase::init() {
	// Initialize operator interface
	oi = new OI();
	
	cout<<"start\n";
	// Initialize subsystems
	chassis       = new Chassis();
	kicker        = new Kicker();
	aircompressor = new AirCompressor();
	cout<<"air compressor\n";
	intake        = new Intake();
	cout<<"intake\n";
	platform      = new Platform();
	cout<<"elevator\n";
	vision        = new Vision();
	cout<<"vision\n";
}
