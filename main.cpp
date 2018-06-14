#include <iostream>
#include "udp_client_server.h"
#include "robotKuka.hpp"
#include <unistd.h>  // sleep,
#include "xml_handler.hpp"

int main() {

    const char* xml_send;
    xml_send = (char*) "arquivo";
    get_data_from_xml_receive(xml_send);

	RobotKuka kr16;

    kr16.startCommunicator((char*)"127.0.0.1", 60010 );

	usleep(5 * 1000 * 1000); // sleep for 5 seconds

    kr16.stopCommunicator();
    
    return 0;
}
