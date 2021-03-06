/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __HiTechnicColorSensor_h__
#define __HiTechnicColorSensor_h__

#include "SensorBase.h"
#include "LiveWindow/LiveWindowSendable.h"

class I2C;

/**
 * HiTechnic NXT Color Sensor.
 *
 * This class allows access to a HiTechnic NXT Color Sensor on an I2C bus.
 * These sensors do not allow changing addresses so you cannot have more
 * than one on a single bus.
 *
 * Details on the sensor can be found here:
 *   http://www.hitechnic.com/index.html?lang=en-us&target=d17.html
 *
 */
class HiTechnicColorSensor : public SensorBase
{
public:
	enum tColorMode {kActive = 0, kPassive = 1, kRaw = 3};
	typedef struct{
		UINT16 red;
		UINT16 blue;
		UINT16 green;
	}RGB;
	explicit HiTechnicColorSensor(UINT8 moduleNumber);
	virtual ~HiTechnicColorSensor();
	UINT8 GetColor();
	UINT8 GetRed();
	UINT8 GetGreen();
	UINT8 GetBlue();
	RGB GetRGB();
	UINT16 GetRawRed();
	UINT16 GetRawGreen();
	UINT16 GetRawBlue();
	RGB GetRawRGB();
	void SetMode(tColorMode mode);
	
	
	//LiveWindowSendable interface
	virtual std::string GetType();
	virtual void InitTable(ITable *subtable);
	virtual void UpdateTable();
	virtual ITable* GetTable();
	virtual void StartLiveWindowMode();
	virtual void StopLiveWindowMode(); 

private:
	static const UINT8 kAddress = 0x02;
	static const UINT8 kManufacturerBaseRegister = 0x08;
	static const UINT8 kManufacturerSize = 0x08;
	static const UINT8 kSensorTypeBaseRegister = 0x10;
	static const UINT8 kSensorTypeSize = 0x08;
	static const UINT8 kModeRegister = 0x41;
	static const UINT8 kColorRegister = 0x42;
	static const UINT8 kRedRegister = 0x43;
	static const UINT8 kGreenRegister = 0x44;
	static const UINT8 kBlueRegister = 0x45;
	static const UINT8 kRawRedRegister = 0x43;
	static const UINT8 kRawGreenRegister = 0x45;
	static const UINT8 kRawBlueRegister = 0x47;
	
	int m_mode;
	I2C* m_i2c;
	ITable *m_table;
};

#endif

