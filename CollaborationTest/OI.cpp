// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "OI.h"
#include "Commands/DrewCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AlexCommand.h"
#include "Commands/AutonomousCommand.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	
	stick = new Joystick(JOYSTICK_PORT);
	trigger = new JoystickButton(stick, Joystick::kTriggerButton);
	trigger->WhenPressed(new DrewCommand);
	button3 = new JoystickButton(stick,3);
	button3->WhenPressed(new LindaCommand);
	
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("AlexCommand", new AlexCommand());

        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	SmartDashboard::PutData("DrewCommand", new DrewCommand());
	SmartDashboard::PutData("LindaCommand", new LindaCommand());
}

Joystick * OI::getJoystick() {
	return stick;
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
