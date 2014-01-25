#include "Intake.h"
#include "../Robotmap.h"
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
	//SetDefaultCommand(new MySpecialCommand());
}

void Intake::Set(double num) {
	intakeRollers->Set(num);
}

void Intake::MoveSolenoid(bool val) {
	if(val) {
		sol->Set(sol->kForward);
	} else {
		sol->Set(sol->kReverse);
	}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

