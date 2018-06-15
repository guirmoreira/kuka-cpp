#include <iostream> // cout, endl,
#include <cstdlib>
#include "robotKuka.hpp"
#include "models.hpp"
#include "xml_handler.hpp"
#include <pthread.h> // thread,
#include <unistd.h>  // sleep,
#include <boost/thread.hpp>
#include <stdio.h>      // Default System Calls
#include <stdlib.h>     // Needed for OS X
#include <string.h>     // Needed for Strlen
#include <sys/socket.h> // Needed for socket creating and binding
#include <netinet/in.h> // Needed to use struct sockaddr_in
#include <time.h>       // To control the timeout mechanism

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


void connection(std::string ip, unsigned int port, bool* running_flag)
{	
	#define EXPR_SIZE   2048
	#define BUFLEN      2048
	#define TRUE        1
	#define SERVERLEN   2048

	std::cout << "IPv4: " << ip << std::endl;

	std::cout << "Porta: " << port << std::endl;

	std::cout << "Flag: " << *running_flag << std::endl;

	int fd;

    if ( (fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror( "socket failed" );
    }

    struct sockaddr_in serveraddr;
    memset( &serveraddr, 0, sizeof(serveraddr) );
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons( 6008 );
    serveraddr.sin_addr.s_addr = htonl( INADDR_ANY );

	struct sockaddr_in clientaddr;
    socklen_t sendsize = sizeof(clientaddr);
	bzero(&clientaddr, sizeof(clientaddr));


    if ( bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ) {
        perror( "bind failed" );
    }


	while (*running_flag)
	{
		char* xml_send = (char*)malloc(sizeof(char) * 2048);

		int length = recvfrom(fd, xml_send, sizeof(char) * 2048 , 0, (struct sockaddr *) &clientaddr, &sendsize );
        if ( length < 0 ) {
            perror( "recvfrom failed" );
            break;
        }

		std::cout << "Msg len: " << length << std::endl;

		xml_send[length] = '\0';

		Data data;
		data = xml_handler::get_data_from_xml_send(const_cast<char*>(xml_send), length);

		data.get_r_ist().print();
		std::cout << data.get_delay() << std::endl;

		//data.print();

		Coordinates move(-0.6, 0, 0, 0, 0, 0);
		Axes axis = Axes();
		DigitalOutputs digout = DigitalOutputs();

		std::string xml_receive;
    	xml_receive = xml_handler::generate_xml_receive(move, axis, digout, data.get_ipoc());

		int send_status = sendto(fd, xml_receive.c_str(), xml_receive.length()*sizeof(char), 0, (struct sockaddr *) &clientaddr, 
								 sendsize);

		free(xml_send);  // pode ser um gargalo
	}

    close( fd );

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