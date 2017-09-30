//
// Created by cameronearle on 9/29/17.
//

#ifndef SNEKCOMMAND_MQTTMANAGER_HPP
#define SNEKCOMMAND_MQTTMANAGER_HPP


#include <string>
#include <client.h>
#include "JoystickPacket.hpp"

class MqttManager {
public:
    void init();

    void openConnection(std::string address, std::string name);
    void closeConnection();

    void send(JoystickPacket packet);

    ~MqttManager() {delete client;}
private:
    mqtt::client *client;
    mqtt::connect_options connOpts;
};


#endif //SNEKCOMMAND_MQTTMANAGER_HPP
