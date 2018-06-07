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

	void set_communicator_running_flag(bool value);
	bool *get_communicator_running_flag();

	pthread_t communication_thread;
	pthread_t control_thread;

  private:
	float CYCLE_TIME;
	bool *communicator_running_flag;

};

#endif // ROBOTKUKA_HPP