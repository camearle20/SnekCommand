//
// Created by cameronearle on 9/29/17.
//

#ifndef SNEKCOMMAND_JOYSTICKPACKET_HPP
#define SNEKCOMMAND_JOYSTICKPACKET_HPP

#include <sstream>
#include <iomanip>

struct JoystickPacket {
    int pitch       = 0;
    int roll        = 0;
    int yaw         = 0;
    int throttle    = 0;

    bool trigger    = false;
    bool thumb      = false;
    bool button3    = false;
    bool button4    = false;
    bool button5    = false;
    bool button6    = false;
    bool button7    = false;
    bool button8    = false;
    bool button9    = false;
    bool button10   = false;
    bool button11   = false;
    bool button12   = false;

    int hat         = -1;

    std::string serialize() {
        std::stringstream ss;
        char sep = ',';
        ss << pitch
           << sep
           << roll
           << sep
           << yaw
           << sep
           << throttle
           << sep
           << trigger
           << sep
           << thumb
           << sep
           << button3
           << sep
           << button4
           << sep
           << button5
           << sep
           << button6
           << sep
           << button7
           << sep
           << button8
           << sep
           << button9
           << sep
           << button10
           << sep
           << button11
           << sep
           << button12
           << sep
           << hat;
        return ss.str();
    }
};

#endif //SNEKCOMMAND_JOYSTICKPACKET_HPP
