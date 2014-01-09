#include "Kickertest.h"
#include "../Robotmap.h"

Kickertest::Kickertest(k) : Subsystem("Kickertest") {
	Kick = new Victor(k);
}
    
void Kickertest::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveCMD());
}

void Kickertest::SetSpeed(double k){
	
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

