//
// Created by cameronearle on 9/29/17.
//

#include "MqttManager.hpp"
#include <unistd.h>

#define TOPIC "Joystick/data"

void MqttManager::init() {
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
}

void MqttManager::openConnection(std::string address, std::string name) {
    client = new mqtt::client(address, name);
    while (true) {
        try {
            client->connect(connOpts);
            std::cout << "Connected to MQTT server at " << address << std::endl;
            break;
        } catch (...) {
            std::cerr << "Error connecting to MQTT server at " << address << ", trying again in 5s" << std::endl;
            sleep(5);
        }
    }
}

void MqttManager::closeConnection() {
    client->disconnect();
}

void MqttManager::send(JoystickPacket packet) {
    auto msg = mqtt::make_message(TOPIC, packet.serialize(), 0, false);
    client->publish(msg);
}