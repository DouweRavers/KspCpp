
#include <iostream>
#include <iomanip>
#include <tuple>
#include <cmath>

#include "KogelCraft.hpp"

using namespace krpc::services;
using namespace douwco;

void KogelCraft::launch(){
    auto autopilot = vessel.auto_pilot();
    autopilot.engage();

    auto control = vessel.control();
    control.set_throttle(1);
    control.activate_next_stage();

    std::cout << "Launch sequence initiated..." << std::endl;

    auto alt_stream = vessel.flight().surface_altitude_stream();
    
    bool aiming_at_target = true;
    bool reached_top = false;
    double alt_prev;
    while (true) {
        double d_lat = target_lat - vessel.flight().latitude();
        double d_lon = target_long - vessel.flight().longitude();

        if(std::abs(d_lat)<0.5 && std::abs(d_lon)<0.5 && aiming_at_target){ 
            vessel.parts().root().experiment().run(); 
            aiming_at_target = false;    
            autopilot.disengage();
        }
        double angle = std::atan2(d_lon, d_lat) * 180/M_PI;
        if(angle < 0) angle = angle + 360;
        if(aiming_at_target) autopilot.target_pitch_and_heading(40, (float)angle);
        double alt = alt_stream();
        double alt_div = alt - alt_prev;
        alt_prev = alt; 
        if(alt_div < 0 && !reached_top){ 
            reached_top = true;
            vessel.control().activate_next_stage();
        }
        if(alt_div < 0 && alt < 3000) { 
            vessel.control().activate_next_stage();
            std::cout << "Initiate shute..." << std::endl;
            return;
        }
    }

}