//
// Created by cameronearle on 9/29/17.
//

#include <iostream>
#include "JoystickManager.hpp"

void JoystickManager::init() {
    if (SDL_Init(SDL_INIT_JOYSTICK) < 0) {
        std::cerr << "Error initializing SDL2!" << std::endl;
        exit(1);
    } else {
        SDL_JoystickEventState(SDL_ENABLE);
    }

    if (SDL_NumJoysticks() < 1) {
        std::cerr << "Warning: No joysticks detected!" << std::endl;
    }
}

void JoystickManager::openJoystick(int id) {
    SDL_Joystick *joystick = SDL_JoystickOpen(id);
    if (!joystick) {
        std::cerr << "Unable to open joystick " << id << std::endl;
    } else {
        std::cout << "Opened joystick " << id << std::endl;
    }
    joysticks.push_back(joystick);
}

void JoystickManager::closeJoysticks() {
    for (auto joystick : joysticks) {
        SDL_JoystickClose(joystick);
    }
}

void JoystickManager::handleEvents() {
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_JOYAXISMOTION:
                axisEvent();
                break;
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
                buttonEvent();
                break;
            case SDL_JOYHATMOTION:
                hatEvent();
                break;
        }
    }
}

void JoystickManager::axisEvent() {
    switch (event.jaxis.axis) {
        case 0: // ROLL
            data.roll = (int) map(event.jaxis.value, -32768, 32767, -100, 100);
            break;
        case 1: // PITCH
            data.pitch = (int) map(event.jaxis.value, -32768, 32767, -100, 100);
            break;
        case 2: // YAW
            data.yaw = (int) map(event.jaxis.value, -32768, 32767, -100, 100);
            break;
        case 3: // THROTTLE
            data.throttle = (int) map(event.jaxis.value, -32768, 32767, -100, 100);
            break;
    }
}

void JoystickManager::buttonEvent() {
    switch (event.jbutton.button) {
        case 0: // TRIGGER
            data.trigger = event.jbutton.state;
            break;
        case 1: // THUMB
            data.thumb = event.jbutton.state;
            break;
        case 2: // 3
            data.button3 = event.jbutton.state;
            break;
        case 3:  // 4
            data.button4 = event.jbutton.state;
            break;
        case 4: // 5
            data.button5 = event.jbutton.state;
            break;
        case 5: // 6
            data.button6 = event.jbutton.state;
            break;
        case 6: // 7
            data.button7 = event.jbutton.state;
            break;
        case 7: // 8
            data.button8 = event.jbutton.state;
            break;
        case 8: // 9
            data.button9 = event.jbutton.state;
            break;
        case 9: // 10
            data.button10 = event.jbutton.state;
            break;
        case 10: // 11
            data.button11 = event.jbutton.state;
            break;
        case 11: // 12
            data.button12 = event.jbutton.state;
            break;
            break;
    }
}

void JoystickManager::hatEvent() {
    switch (event.jhat.value) {
        case SDL_HAT_RIGHTUP:
            data.hat = 45;
            break;
        case SDL_HAT_RIGHTDOWN:
            data.hat = 135;
            break;
        case SDL_HAT_LEFTDOWN:
            data.hat = 225;
            break;
        case SDL_HAT_LEFTUP:
            data.hat = 315;
            break;
        case SDL_HAT_UP:
            data.hat = 0;
            break;
        case SDL_HAT_RIGHT:
            data.hat = 90;
            break;
        case SDL_HAT_DOWN:
            data.hat = 180;
            break;
        case SDL_HAT_LEFT:
            data.hat = 270;
            break;
        default:
            data.hat = -1;
            break;
    }
}

JoystickPacket JoystickManager::read() {
    return data;
}