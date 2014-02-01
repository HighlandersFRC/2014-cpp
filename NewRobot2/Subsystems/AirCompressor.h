#ifndef AIRCOMPRESSOR_H
#define AIRCOMPRESSOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class AirCompressor: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Compressor *compressor;
	
public:
	AirCompressor();
	void InitDefaultCommand();
	void Stop();
	void Start();
};

#endif
