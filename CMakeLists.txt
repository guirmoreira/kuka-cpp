cmake_minimum_required(VERSION 3.8)
project(kukacpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp udp_client_server.h udp_example.cpp)
add_executable(kukacpp ${SOURCE_FILES})