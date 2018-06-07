#include <iostream>
#include "udp_client_server.h"
#include <unistd.h>

int main()
{
    std::cout << "\nStarting client..." << std::endl;
    udp_client_server::udp_client client("127.0.0.1", 60010);
    std::cout << "Addr: " << client.get_addr() << " | Port: " << client.get_port() << std::endl;
    int i;
    for (i = 0; i < 30; i++)
    {
        std::string message = "This is the message ";
        client.send(message.c_str(), sizeof(char) * 64);
        std::cout << "Message [ " << message << i << " ] sent." << std::endl;
        usleep(12*1000);
    }
    return 0;
}