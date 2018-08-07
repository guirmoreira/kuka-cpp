#ifndef ROBOTKUKA_HPP
#define ROBOTKUKA_HPP
#include <pthread.h>
#include "models.hpp"
#include <queue> 

class RobotKuka
{
public:
	RobotKuka(float CYCLE_TIME);
	RobotKuka();

	void startCommunicator(char *const ip, unsigned int port);
	void stopCommunicator();
	void move(Vector vector, double time);

private:
	void set_communicator_running_flag(bool value);
	bool *get_communicator_running_flag();
	
	float CYCLE_TIME;
	bool *communicator_running_flag;

	std::queue<Vector> move_queue;

	Vector security_limit_speed(1.0 , 1.0 , 1.0 ,	// [m/s]
								60.0, 60.0, 60.0);  // [deg/s];
};

#endif // ROBOTKUKA_HPP