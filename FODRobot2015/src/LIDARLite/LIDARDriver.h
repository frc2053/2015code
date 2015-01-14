//Drew Williams
//Team 2053 Tigertronics
//FOD Robot LIDAR Driver
//Port LIDAR Driver to C++
//1/13/15

#include "PIDSource.h"
#include "SerialPort.h"
#include "Task.h"
#include "WPILib.h"

#ifndef SRC_LIDARLITE_LIDARDRIVER_H_
#define SRC_LIDARLITE_LIDARDRIVER_H_

class LIDAR
{
protected:
	I2C *pIC2;
	unsigned short distance [];
};



#endif /* SRC_LIDARLITE_LIDARDRIVER_H_ */
