#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

// Import Command.h
#include "Commands/Command.h"

// Import Operator Interface
#include "OI.h"

// Import Subsystems
#include "Subsystems/Chassis.h"
#include "Subsystems/Kicker.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Platform.h"
#include "Subsystems/Nomos.h"
#include "Subsystems/Sensors.h"

/*
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
*/
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	
	// Operator interface
	static OI *oi;
	
	// Create single static instance of subsystems
	static Chassis       *chassis;
	static Kicker        *kicker;
	static AirCompressor *aircompressor;
	static Intake *intake;
	static Platform *platform;
	static Nomos *nomos;
	static Sensors       *sensors;
};

#endif
