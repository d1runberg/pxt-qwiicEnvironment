/**
* Andy England @ SparkFun Electronics
* September 6, 2018
* https://github.com/sparkfun/pxt-light-bit
*
* Development environment specifics:
* Written in Microsoft PXT
* Tested with a SparkFun temt6000 sensor and micro:bit
*
* This code is released under the [MIT License](http://opensource.org/licenses/MIT).
* Please review the LICENSE.md file included with this example. If you have any questions
* or concerns with licensing, please contact techsupport@sparkfun.com.
* Distributed as-is; no warranty is given.
*/


#include "pxt.h"
#include <cstdint>
#include "SparkFunEnvironment.h"

using namespace pxt;

namespace qwiicEnvironment {
	//MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);
	environment *qwiicEnvironmentCombo; //BME280 handles our Temp, pressure, and humidity

	//%
	void beginEnvironment()
	{
		qwiicEnvironmentCombo->begin();
	}
	
	//%
	float getMeasurement(uint8_t type)
	{
		float value;
		switch (type)
		{
			case 1:
				value = qwiicEnvironmentCombo->readTempC();
				break;
			case 2:
				value = qwiicEnvironmentCombo->readTempF();
				break;
			case 3:
				value = qwiicEnvironmentCombo->readFloatHumidity();
				break;
			case 4:
				value = qwiicEnvironmentCombo->readFloatPressure();
				break;
			case 5:
				if (qwiicEnvironmentCombo->dataAvailable())
				{
					qwiicEnvironmentCombo->readAlgorithmResults();
				}
				value = qwiicEnvironmentCombo->getCO2();
				break;
			case 6:
				if (qwiicEnvironmentCombo->dataAvailable())
				{
					qwiicEnvironmentCombo->readAlgorithmResults();
				}
				value = qwiicEnvironmentCombo->getTVOC();
				break;
			default:
				value = 0;
				break;
		}
		return value;
	}
}