cmake_minimum_required(VERSION 3.6)
project(SnekCommand)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include/mqtt) #Paho MQTT
include_directories(/usr/include/SDL2)

link_directories(/usr/local/lib)

set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so) #SDL2

file(GLOB SNEK_COMMAND_SRC
        "*.hpp"
        "*.cpp")

add_executable(SnekCommand ${SNEK_COMMAND_SRC})
target_link_libraries(SnekCommand paho-mqttpp3 ${SDL2_LIBRARY})