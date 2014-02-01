#include "AirCompressor.h"
#include "../Robotmap.h"
#include "../Commands/CompressorCMD.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor") {
	compressor = new Compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY);
}
    
void AirCompressor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CompressorCMD());
}

void AirCompressor::Stop() {
	compressor->Stop();
}

void AirCompressor::Start() {
	compressor->Start();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
