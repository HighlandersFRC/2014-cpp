#include "SensorsUpdate.h"
#include "..\Subsystems\Sensors.h"

SensorsUpdate::SensorsUpdate() {
	// Use Requires() here to declare subsystem dependencies
	Requires(sensors);
}

// Called just before this Command runs the first time
void SensorsUpdate::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void SensorsUpdate::Execute() {
	sensors->get_DS_Distance();
	sensors->get_Gyro_Distance();
}

// Make this return true when this Command no longer needs to run execute()
bool SensorsUpdate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SensorsUpdate::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SensorsUpdate::Interrupted() {
}
