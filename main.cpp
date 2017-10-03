#include <iostream>
#include <unistd.h>
#include "JoystickManager.hpp"
#include "MqttManager.hpp"

#define JOYSTICK_ID 0 //<- SET JOYSTICK ID HERE

int main() {
    JoystickManager joystickManager; //Create a joystick manager to hold our joysticks
    MqttManager mqttManager;       //Create an mqtt manager to send our data

    joystickManager.init(); //Initialize the joystick manager
    mqttManager.init();     //Initialize the mqtt manager

    joystickManager.openJoystick(JOYSTICK_ID);                //Open the joystick
    mqttManager.openConnection("127.0.0.1", "JoystickBridge"); //Open the mqtt connection

    for (;;) {
        joystickManager.handleEvents();
        mqttManager.send(joystickManager.read());
        usleep(10000);
    }
}