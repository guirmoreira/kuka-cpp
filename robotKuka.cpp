#include <iostream> 			// cout, endl,
#include <cstdlib>
#include <unistd.h>  			// sleep,
#include <boost/thread.hpp>
#include <stdio.h>      		// Default System Calls
#include <stdlib.h>     		// Needed for OS X
#include <string.h>     		// Needed for Strlen
#include <sys/socket.h> 		// Needed for socket creating and binding
#include <netinet/in.h> 		// Needed to use struct sockaddr_in
#include <time.h>       		// To control the timeout mechanism
#include <chrono>
#include <queue> 				// queue

#include "robotKuka.hpp"
#include "models.hpp"
#include "xml_handler.hpp"


/*
RobotKuka::RobotKuka(float CYCLE_TIME)
 - This is the RobotKuka class constructor that receives cycle_time value. Cycle_time definition is important
 in order to configure movementation functions, since each part of movement will be executed at this time in-
 terval.
 ~ Arguments: (float) CYCLE_TIME
 ~ Returns: none
*/
RobotKuka::RobotKuka(float CYCLE_TIME)
{
	this->CYCLE_TIME = CYCLE_TIME;
}

/*
RobotKuka::RobotKuka()
 - This is the default RobotKuka class constructor that receives cycle_time = 0.012 as default value. 
 ~ Arguments: none
 ~ Returns: none
*/
RobotKuka::RobotKuka()
{
	this->CYCLE_TIME = 0.012;
}

/*
void RobotKuka::set_communicator_running_flag(bool value)
 - This function sets the boolean value to communicator_running_flag, flag responsible to states if communi-
 cation is running or not.
 ~ Arguments: (bool) value
 ~ Returns: void
*/
void RobotKuka::set_communicator_running_flag(bool value)
{
	this->communicator_running_flag = &value;
}

/*
bool* RobotKuka::get_communicator_running_flag()
 - This function returns the pointer to the boolean value of communicator_running_flag, flag responsible to 
 states if communication is running or not.
 ~ Arguments: none
 ~ Returns: (bool*) communicator_runnung_flag
*/
bool* RobotKuka::get_communicator_running_flag()
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

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror( "socket failed" );
    }

    struct sockaddr_in serveraddr;
    memset( &serveraddr, 0, sizeof(serveraddr) );
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons( port );
    serveraddr.sin_addr.s_addr = htonl( INADDR_ANY );

	struct sockaddr_in clientaddr;
    socklen_t sendsize = sizeof(clientaddr);
	bzero(&clientaddr, sizeof(clientaddr));


    if (bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
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

        /* Starts chrono to account CYCLE TIME */
		//auto started = std::chrono::high_resolution_clock::now();

		std::cout << "Msg len: " << length << std::endl;

		xml_send[length] = '\0';  // This is necessary to avoid xml_parse errors;

		/* Gets all data read from received XML Send and puts it into a instance of Data. */
		Data data;
		data = xml_handler::get_data_from_xml_send(const_cast<char*>(xml_send), length);

		//data.get_r_ist().print();
		//std::cout << data.get_delay() << std::endl;

		//data.print();

		std::string xml_receive;  // creates string for XML Receive

		/* Creates void instances of vector, axis and digital outputs to send thru XML Receive. */
		Vector vector = Vector();
		Axes axis = Axes();
		DigitalOutputs digout = DigitalOutputs();

		/* Push one element from the queue if the movement queue is not empty. If the queue is empty,
		the void instances are placed. */
		if (!this->queue_move.empty())
		{
			vector = this->queue_move.front();
			myqueue.pop();
		}

		/* Generates the XML Receive string using the vector, axis, and digital outputs instances and
		the previous XML Send IPOC value. */
    	xml_receive = xml_handler::generate_xml_receive(vector, axis, digout, data.get_ipoc());

    	/* Sends the XML Receive string thru the socket created previously. */
		int send_status = sendto(fd, xml_receive.c_str(), xml_receive.length()*sizeof(char), 0, (struct sockaddr *) &clientaddr, 
								 sendsize);

		/* Free the allocated space for XML Send string. */
		free(xml_send);  // might be a bottleneck <!>

		/* Stops chrono to account CYCLE TIME. */
		//auto done = std::chrono::high_resolution_clock::now();
		//std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(done-started).count();
	}


	/* Closes the previously openned communication socket. */
    close(fd);

    /* Exists the previously created communication thread. */
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


void split_vector(Vector vector, double time)
{
	int packages_ammount = (int) time/this->CYCLE_TIME;

	Vector package_move(vector.get_x()/packages_ammount, 
						vector.get_y()/packages_ammount, 
						vector.get_z()/packages_ammount, 
						vector.get_a()/packages_ammount, 
						vector.get_b()/packages_ammount, 
						vector.get_c()/packages_ammount);

	Vector package_speed(package_move.get_x()/CYCLE_TIME, 
						 package_move.get_y()/CYCLE_TIME, 
						 package_move.get_z()/CYCLE_TIME, 
						 package_move.get_a()/CYCLE_TIME, 
						 package_move.get_b()/CYCLE_TIME, 
						 package_move.get_c()/CYCLE_TIME);

	if(package_speed.get_x() > this->security_limit_speed.get_x() || 
	   package_speed.get_y() > this->security_limit_speed.get_y() || 
	   package_speed.get_z() > this->security_limit_speed.get_z() || 
	   package_speed.get_a() > this->security_limit_speed.get_a() || 
	   package_speed.get_b() > this->security_limit_speed.get_b() || 
	   package_speed.get_c() > this->security_limit_speed.get_c())
	{
		std::cout << "ERROR | Security: security_limit_speed exceeded while planning path. Check the log." << std::endl;
		RobotKuka::stopCommunicator();
	} else if(package_speed.get_x() > this->security_limit_speed.get_x()/2 || 
	   		  package_speed.get_y() > this->security_limit_speed.get_y()/2 || 
	   		  package_speed.get_z() > this->security_limit_speed.get_z()/2 || 
	   		  package_speed.get_a() > this->security_limit_speed.get_a()/2 || 
	   		  package_speed.get_b() > this->security_limit_speed.get_b()/2 || 
	   		  package_speed.get_c() > this->security_limit_speed.get_c()/2)
	{
		std::cout << "WARNING | Security: half of security_limit_speed exceeded while planning path. Check the log." << std::endl;
	}

	for(i = 0; i < packages_ammount; i++)
	{
		try
		{
			this->queue_move.push(package_move);
		}
		catch(exception& e)
		{
			std::cout << "ERROR | Exception: problem while pushing element to queue_move (" << e.what() << ") . Check the log." << std::endl;
		}
	}

	std::cout << "LOG | " << packages_ammount << " elements pushed to queue_move." << std::endl;

	pthread_exit(NULL);
}


void RobotKuka::move(Vector vector, double time)
{
	boost::thread split_vector_thread(split_vector, vector, time);
}