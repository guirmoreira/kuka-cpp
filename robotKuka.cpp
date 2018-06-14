#include <iostream> // cout, endl,
#include <stdlib.h>
#include <cstdlib>
#include "robotKuka.hpp"
#include "udp_client_server.h"
#include <pthread.h> // thread,
#include <unistd.h>  // sleep,
#include <boost/thread.hpp>

// Threads awsome tutorial: https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm

RobotKuka::RobotKuka(float CYCLE_TIME)
{
	this->CYCLE_TIME = CYCLE_TIME;
}

RobotKuka::RobotKuka()
{
	this->CYCLE_TIME = 0.012;
}

void RobotKuka::set_communicator_running_flag(bool value)
{
	this->communicator_running_flag = &value;
}

bool *RobotKuka::get_communicator_running_flag()
{
	return this->communicator_running_flag;
}


void connection(char *const ip, unsigned int port, bool* running_flag)
{	
	std::cout << "IPv4: " << ip << std::endl;

	std::cout << "Porta: " << port << std::endl;

	std::cout << "Flag: " << *running_flag << std::endl;

	udp_client_server::udp_server server(ip, port);

	while (*running_flag)
	{
		char *messageBuffer = (char *)malloc(sizeof(char) * 64);
		server.recv(messageBuffer, sizeof(char) * 64);
		std::cout << "Message: " << messageBuffer << std::endl;
		free(messageBuffer);
	}

	pthread_exit(NULL);
}


void RobotKuka::startCommunicator(char *const ip, unsigned int port)
{
	std::cout << "Comunicação iniciada..." << std::endl;

	bool flag = true;

	RobotKuka::set_communicator_running_flag(flag);

	boost::thread communication_thread(connection, ip, port, communicator_running_flag);

}

void RobotKuka::stopCommunicator()
{
	bool flag = false;
	RobotKuka::set_communicator_running_flag(flag);
}