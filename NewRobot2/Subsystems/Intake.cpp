#include "Intake.h"
#include "../Robotmap.h"
#include "../DebugPrint.h"

/*TODO: Double Solenoid (used as single solenoid) pneumatics
 * must raise the intake when ready to fire Kicker through button.
 * A PG 188 motor must be configured for the axel to drive the
 * intake wheels forward, backward, or stopped.
*/
Intake::Intake() : Subsystem("Intake") {
	intakeRollers = new Talon(INTAKE_MOTOR);
	sol = new DoubleSolenoid(SOL_A, SOL_B);
}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
}

void Intake::Set(double num) {
	intakeRollers->Set(num);
}

void Intake::MoveSolenoid(bool val) {
	if(val) {
		sol->Set(sol->kForward);
#if (FULL_PRINT==1)	
		SmartDashboard::PutString(SD_INTAKE_ARM_POS, SD_STRING_LOWERED);
#endif		
	} else {
		sol->Set(sol->kReverse);
#if (FULL_PRINT==1)
		SmartDashboard::PutString(SD_INTAKE_ARM_POS, SD_STRING_RAISED);
#endif		
	}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

