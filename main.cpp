#include <iostream>
#include "udp_client_server.h"
#include "robotKuka.hpp"
#include <unistd.h>  // sleep,

int main() {

	RobotKuka kr16;

    kr16.startCommunicator("192.168.10.15", 6008);

	usleep(10 * 1000 * 1000); // sleep for 5 seconds

    kr16.stopCommunicator();
    
    return 0;
}
