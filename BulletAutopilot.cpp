
#include <iostream>
#include <iomanip>
#include <tuple>

#include "BulletAutopilot.hpp"

using namespace krpc::services;

douwco::BulletAutopilot::BulletAutopilot(SpaceCenter::Vessel v){
    vessel = v;
}

void douwco::BulletAutopilot::start_launch_sequence(){
    auto autopilot = vessel.auto_pilot();
    autopilot.target_pitch_and_heading(45, 90);
    autopilot.engage();

    auto control = vessel.control();
    control.set_throttle(1);
    control.activate_next_stage();

    std::cout << "Launch sequence initiated..." << std::endl;
}

void douwco::BulletAutopilot::run_flight_autopilot(){
    auto alt_stream = vessel.flight().surface_altitude_stream();
    
    double alt_prev;
    while (true) {
        double alt = alt_stream();
        double alt_div = alt - alt_prev;
        alt_prev = alt; 
        if(alt_div < 0 && alt < 3000) { 
            vessel.control().activate_next_stage();
            std::cout << "Initiate shute..." << std::endl;
            return;
        }
    }
}