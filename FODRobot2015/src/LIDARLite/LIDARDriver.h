/*#ifndef SRC_LIDARLITE_LIDARDRIVER_H_
#define SRC_LIDARLITE_LIDARDRIVER_H_

class LIDAR
{
private:
	I2C i2c;
	unsigned short distance [];
	Timer *Timer;

	const int LIDAR_ADDR = 0x62;
	const int LIDAR_CONFIG_REGISTER = 0x00;
	const int LIDAR_DISTANCE_REGISTER = 0x8f;
};



#endif /* SRC_LIDARLITE_LIDARDRIVER_H_ */
