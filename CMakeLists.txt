cmake_minimum_required(VERSION 3.5)
project(kukacpp)

set(CMAKE_CXX_STANDARD 11)

set(RAPIDXML_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/rapidxml-1.13)
set(UDP_CLIENT_SERVER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/udp-client-server)
set(UTILS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/utils)

find_package(Boost COMPONENTS thread REQUIRED)

set(MAIN_SOURCE_FILES main.cpp robotKuka.cpp robotKuka.hpp)
set(RAPIDXML_INCLUDE_FILES ${RAPIDXML_PATH}/rapidxml.hpp ${RAPIDXML_PATH}/rapidxml_iterators.hpp ${RAPIDXML_PATH}/rapidxml_print.hpp ${RAPIDXML_PATH}/rapidxml_utils.hpp)
set(UDP_CLIENT_SERVER_INCLUDE_FILES ${UDP_CLIENT_SERVER_PATH}/udp_client_server.h ${UDP_CLIENT_SERVER_PATH}/udp_client_server.cpp)
set(XML_FILES ${UTILS_PATH}/xml_handler.hpp)
set(MODELS_FILES ${UTILS_PATH}/models.hpp ${UTILS_PATH}/models.cpp)

include_directories(${Boost_INCLUDE_DIRS}) 

add_executable(${PROJECT_NAME} 
               ${MAIN_SOURCE_FILES} 
               ${RAPIDXML_INCLUDE_FILES} 
               ${UDP_CLIENT_SERVER_INCLUDE_FILES} 
               ${XML_FILES} 
               ${MODELS_FILES})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${RAPIDXML_PATH} ${UDP_CLIENT_SERVER_PATH} ${UTILS_PATH})

set(CLIENT_SOURCE_FILES client.cpp ${UDP_CLIENT_SERVER_INCLUDE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES})
target_include_directories(client PRIVATE ${UDP_CLIENT_SERVER_PATH})