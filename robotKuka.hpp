#ifndef ROBOTKUKA_HPP
#define ROBOTKUKA_HPP
#include <pthread.h>

class RobotKuka
{
public:
	RobotKuka(float CYCLE_TIME);
	RobotKuka();

	void startCommunicator(char *const ip, unsigned int port);
	void stopCommunicator();
	void move()

private:
	void set_communicator_running_flag(bool value);
	bool *get_communicator_running_flag();
	
	float CYCLE_TIME;
	bool *communicator_running_flag;
};

#endif // ROBOTKUKA_HPP