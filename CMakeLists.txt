cmake_minimum_required(VERSION 3.6)
project(SnekCommand)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include/mqtt) #Paho MQTT
include_directories(/usr/include/SDL2)

option(PI_BUILD "Is this being built on a pi?" OFF)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
if (PI_BUILD)
    set(SDL2_LIBRARY /usr/lib/arm-linux-gnueabihf/libSDL2.so) #TODO Find the path of sdl2 on the pi
else()
    set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so)
endif()

link_directories(/usr/local/lib)

file(GLOB SNEK_COMMAND_SRC
        "*.hpp"
        "*.cpp")

add_executable(SnekCommand ${SNEK_COMMAND_SRC})
target_link_libraries(SnekCommand paho-mqttpp3 ${SDL2_LIBRARY})