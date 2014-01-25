#include "WPILib.h"
#include "Commands/Command.h"
//#include "Commands/ExampleCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	//Command *autonomousCommand;
	//LiveWindow *lw;
	
	/* RobotInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when robot is started (including reboot)
	*/
	virtual void RobotInit() {
		CommandBase::init();
		//@todo Drago901 1/11/14 Replace the example command with our actual autonomous command
		//autonomousCommand = new ExampleCommand();
		//lw = LiveWindow::GetInstance();
		
		//SmartDashboard Values (Defaults for values that read from SmartDashboard)
		SmartDashboard::PutNumber("Kicker Max Speed Forward", .75);
		SmartDashboard::PutNumber("Intake Speed", .2);
		//SmartDashboard::PutNumber("Belt Speed, ")
	}
	
	
	/* AutonomousInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when the autonomous period is started
	*/
	virtual void AutonomousInit() {
		//autonomousCommand->Start();
	}
	
	
	/* AutonomousPeriodic()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs repeatedly during the autonomous period 
	*/
	virtual void AutonomousPeriodic() {
		//Scheduler::GetInstance()->Run();
	}
	
	
	/* TeleopInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when teleoperated period is started
	*/
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//autonomousCommand->Cancel();
	}
	
	
	/* TeleopPeriodic()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs repeatedly during the 
	 * teleoperated period 
	*/
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	
	/* TestPeriodic()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs repeatedly during the test period
	*/
	virtual void TestPeriodic() {
		//lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

