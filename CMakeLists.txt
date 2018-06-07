cmake_minimum_required(VERSION 3.5)
project(kukacpp)

set(CMAKE_CXX_STANDARD 11)

set(MAIN_SOURCE_FILES main.cpp udp_client_server.h udp_client_server.cpp robotKuka.cpp robotKuka.hpp)

add_executable(kukacpp ${MAIN_SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(kukacpp Threads::Threads)

set(CLIENT_SOURCE_FILES client.cpp udp_client_server.h udp_client_server.cpp)
add_executable(client ${CLIENT_SOURCE_FILES})