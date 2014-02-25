#include "WPILib.h"
#include "DebugPrint.h"			// for: DebugPrint()
#include "Commands/Command.h"
#include "Commands/Teleop.h"
#include "Commands/Autonomous.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot 
{
private:
	// @todo: CLEAN Command *autonomousCommand;
	Autonomous *autonomous;
	Teleop     *teleop;
	
	
	/* RobotInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when robot is started (including reboot)
	*/
	virtual void RobotInit() 
	{
		DebugPrint(DBG_PRT_V1, "calling: CommandBase::init()");
		CommandBase::init();

		DebugPrint(DBG_PRT_V1, "calling: new Autonomous()");
		autonomous = new Autonomous();

		DebugPrint(DBG_PRT_V1, "calling: new Teleop()");
		teleop     = new Teleop();
	}
	
	
	/* AutonomousInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when the autonomous period is started
	*/
	virtual void AutonomousInit() 
	{
		DebugPrint(DBG_PRT_V1, "called: AutonomousInit()");

		// @todo: CLEAN autonomousCommand->Start();
		autonomous->Start();
		teleop->Cancel();
	}
	
	
	/* AutonomousPeriodic()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs repeatedly during the autonomous period 
	*/
	virtual void AutonomousPeriodic() 
	{
		Scheduler::GetInstance()->Run();
	}
	
	
	/* TeleopInit()
	 * Inputs  -
	 *  None
	 * Returns -
	 * 	None
	 * 
	 * Runs when teleoperated period is started
	*/
	virtual void TeleopInit() 
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		
		DebugPrint(DBG_PRT_V1, "called: TeleopInit()");

		// @todo: CLEAN autonomousCommand->Cancel();
		autonomous->Cancel();
		teleop->Start();
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
	virtual void TeleopPeriodic() 
	{
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
	virtual void TestPeriodic() 
	{
		CommandBase::lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

