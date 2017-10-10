//
// Created by cameronearle on 9/29/17.
//

#ifndef SNEKCOMMAND_JOYSTICKMANAGER_HPP
#define SNEKCOMMAND_JOYSTICKMANAGER_HPP

#include <SDL.h>
#include <vector>
#include "JoystickPacket.hpp"

#define JOYSTICK_RANGE 0x8000

class JoystickManager {
public:
    void init();

    void openJoystick(int id);
    void closeJoysticks();

    void handleEvents();

    JoystickPacket read();

    ~JoystickManager() {closeJoysticks();}
private:
    std::vector<SDL_Joystick *> joysticks;
    JoystickPacket data;

    SDL_Event event;

    void axisEvent();
    void buttonEvent();
    void hatEvent();
    double map(double x, double oldMin, double oldMax, double newMin, double newMax) {
        return (newMax - newMin) * (x - oldMin) / (oldMax - oldMin) + newMin;
    }

};


#endif //SNEKCOMMAND_JOYSTICKMANAGER_HPP
