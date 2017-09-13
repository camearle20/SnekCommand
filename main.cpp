#include <iostream>
#include <string>
#include <client.h>

int main() {
    mqtt::client client("test.mosquitto.org:1883", "SnekTestClient");
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    client.connect(connOpts);

    auto msg = mqtt::make_message("SnekTest/test", "test", 1, false);

    client.publish(msg);

    client.subscribe("SnekTest/test");
    auto recv = client.consume_message();

    std::cout << recv->to_string() << std::endl;

}