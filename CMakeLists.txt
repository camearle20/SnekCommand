cmake_minimum_required(VERSION 3.6)
project(SnekCommand)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include/mqtt) #Paho MQTT
include_directories(/usr/include/SDL2)

link_directories(/usr/local/lib)

set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so) #SDL2

set(SOURCE_FILES main.cpp)
add_executable(SnekCommand ${SOURCE_FILES})
target_link_libraries(SnekCommand paho-mqttpp3 ${SDL2_LIBRARY})