#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/DriveCMD.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	Command *teleopDrive;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		teleopDrive = new DriveCMD();
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
		teleopDrive->Cancel();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
		teleopDrive->Run();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);
