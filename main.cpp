#include <iostream>
#include "robotKuka.hpp"
#include <unistd.h>  // sleep,

int main() {

	RobotKuka kr16;

	kr16.startCommunicator("192.168.10.15", 6008);

	Vector vector(100, 0, 0, 0, 0, 0);

	kr16.move(vector, 4.0);

	usleep(10 * 1000 * 1000); // sleep for 10 seconds

    kr16.stopCommunicator();
    
    return 0;
}
