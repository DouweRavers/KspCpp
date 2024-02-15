#include <iostream>
#include "spacecraft/KogelCraft.hpp"

using namespace douwco;

int main() {
    std::cout << "Starting session" << std::endl;

    auto conn = krpc::connect("autopilot", "192.168.0.171");
    SpaceCenter space_center(&conn);

    SpaceCenter::Waypoint target = space_center.waypoint_manager().waypoints()[0];

    auto vessel = space_center.active_vessel();

    std::cout << "Starting autopilot for " << vessel.name() << std::endl;

    auto autopilot = KogelCraft(vessel, target.latitude(), target.longitude());
    autopilot.launch();

    std::cout << "autopilot finished" << std::endl;
    return 0;
}
