#include <iostream> // cout, endl,
#include <stdlib.h>
#include <cstdlib>
#include "robotKuka.hpp"
#include "udp_client_server.h"
#include <pthread.h> // thread,
#include <unistd.h>  // sleep,
#include <boost/thread.hpp>

// Threadrrs awsome tutorial: https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm

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

struct connection_info
{
	const char *ip;
	unsigned int port;
	bool *running_flag;
};

void *connection(void *args)
{	

	struct connection_info *connection_info;
	//connection_info = (struct connection_info *) malloc(sizeof(struct connection_info));
	connection_info = (struct connection_info *)args;

	const char *ip = connection_info->ip;
	unsigned int port = connection_info->port;
	bool *running_flag = connection_info->running_flag;

	std::cout << "IPv4: " << ip << std::endl;

	std::cout << "Porta: " << connection_info->port << std::endl;

	udp_client_server::udp_server server(connection_info->ip, connection_info->port);

	//free(connection_info);


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

	struct connection_info con_info;
	con_info.ip = ip;
	con_info.port = port;
	con_info.running_flag = communicator_running_flag;
	int rc;

	RobotKuka::set_communicator_running_flag(true);

	rc = pthread_create(&communication_thread, NULL, &connection, (void *)&con_info);
	if(rc){
		std::cout << "Falha ao criar a thread de comunicação. Saindo..." << std::endl;
		exit(-1);
	}

	rc = pthread_join(communication_thread, NULL);
	usleep(500);
	rc = pthread_detach(communication_thread);

	std::cout << "rc: " << rc << std::endl;



}

void RobotKuka::stopCommunicator()
{
	*communicator_running_flag = false;
}