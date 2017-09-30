//
// Created by cameronearle on 9/29/17.
//

#include "MqttManager.hpp"

#define TOPIC "Joystick/data"

void MqttManager::init() {
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
}

void MqttManager::openConnection(std::string address, std::string name) {
    client = new mqtt::client(address, name);
    client->connect(connOpts);
}

void MqttManager::closeConnection() {
    client->disconnect();
}

void MqttManager::send(JoystickPacket packet) {
    auto msg = mqtt::make_message(TOPIC, packet.serialize(), 1, false);
    client->publish(msg);
}