#include "DriveCMD.h"
#include "..\CommandBase.h"


DriveCMD::DriveCMD() {
	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DriveCMD::Initialize() {
	drivetrain->Stop();
	cout<<__FILE__<<" "<<__LINE__<<": INIT\n";
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute() {
	// Get Joystick axis values
	double x_left  = oi->joystick_1->GetX(); // left joystick x-axis
	double y_left  = oi->joystick_1->GetY(); // left joystick y-axis
	double x_right = oi->joystick_2->GetX(); // right joystick x-axis
	double y_right = oi->joystick_2->GetY(); // right joystick y-axis
	cout<<__FILE__<<" "<<__LINE__<<": EXECUTE\n";
	drivetrain->TankDrive(y_left, y_right);      // Tank Drive control style (two joysticks)
	//drivetrain->ArcadeDrive(x_left, y_left);     //Arcade Drive control style (one joystick)
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveCMD::End() {
	cout<<__FILE__<<" "<<__LINE__<<": END\n";
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCMD::Interrupted() {
	cout<<__FILE__<<" "<<__LINE__<<": INTERRUPTED\n";
	drivetrain->Stop();
}
