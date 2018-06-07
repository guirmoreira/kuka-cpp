#include <iostream>
#include "udp_client_server.h"
#include "robotKuka.hpp"
#include <unistd.h>  // sleep,

int main() {

	RobotKuka kr16;

    kr16.startCommunicator( (char*) "127.0.0.1", 60010 );

    std::cout << "Aqui não entrou..." << std::endl;

	usleep(5 * 1000 * 1000); // sleep for 5 seconds

    kr16.stopCommunicator();
    
    return 0;
}
