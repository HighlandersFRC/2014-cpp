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

void AirCompressor::Update() {
	if (compressor->GetPressureSwitchValue()) {
		SmartDashboard::PutString("Compressor", "OFF");
	}
	else {
		SmartDashboard::PutString("Compressor", "ON");
	}
}

void AirCompressor::Stop() {
	compressor->Stop();
	SmartDashboard::PutString("Compressor", "OFF");
}

void AirCompressor::Start() {
	compressor->Start();
	SmartDashboard::PutString("Compressor", "ON");
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
