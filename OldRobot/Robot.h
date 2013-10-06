// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Commands/TeleopDrive.h"
#include "Subsystems/Articulator.h"
#include "Subsystems/Belt.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Indexer.h"
#include "Subsystems/Injector.h"
#include "Subsystems/Launcher.h"
#include "Subsystems/Shoulder.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/TeleopDrive.h"
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	Command *driveCommand;
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DriveBase* driveBase;
	static Belt* belt;
	static Shoulder* shoulder;
	static Injector* injector;
	static Launcher* launcher;
	static Indexer* indexer;
	static Articulator* articulator;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
