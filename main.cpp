#include <iostream>
#include "BulletAutopilot.hpp"


int main() {
    std::cout << "Starting session" << std::endl;

    auto conn = krpc::connect("autopilot", "192.168.0.171");
    SpaceCenter space_center(&conn);

    auto vessel = space_center.active_vessel();

    std::cout << "Starting autopilot for " << vessel.name() << std::endl;

    auto autopilot = douwco::BulletAutopilot(vessel);
    autopilot.start_launch_sequence();
    autopilot.run_flight_autopilot();

    std::cout << "autopilot finished" << std::endl;
    return 0;
}
