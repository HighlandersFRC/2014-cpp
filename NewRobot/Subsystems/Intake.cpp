#include "Intake.h"
#include "../Robotmap.h"
/*TODO: Double Solenoid (used as single solenoid) Pneumatics
 * must raise the intake when ready to fire Kicker through button.
 * A PG 188 motor must be configured for the axel to drive the
 * intake wheels forward, backward, or stopped.
*/
Intake::Intake() : Subsystem("Intake") {
	
}
    
void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

