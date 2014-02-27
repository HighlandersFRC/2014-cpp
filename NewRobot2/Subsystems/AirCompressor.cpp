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
		SmartDashboard::PutString(SD_COMPRESSOR, SD_STRING_OFF);
	}
	else {
		SmartDashboard::PutString(SD_COMPRESSOR, SD_STRING_ON);
	}
}

void AirCompressor::Stop() {
	compressor->Stop();
	SmartDashboard::PutString(SD_COMPRESSOR, SD_STRING_OFF);
}

void AirCompressor::Start() {
	compressor->Start();
	SmartDashboard::PutString(SD_COMPRESSOR, SD_STRING_ON);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
