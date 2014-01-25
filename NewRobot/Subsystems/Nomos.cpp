#include "Nomos.h"
#include "../Robotmap.h"

Nomos::Nomos() : Subsystem("Nomos") {
	sol = new DoubleSolenoid(SOL_A, SOL_B);
}
    
void Nomos::InitDefaultCommand() {
}

void Nomos::MoveSolenoid(bool val) {
	if(val) {
		sol->Set(sol->kForward);
	} else {
		sol->Set(sol->kReverse);
	}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
