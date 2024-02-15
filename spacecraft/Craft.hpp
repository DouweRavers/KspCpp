#ifndef CRAFT_H
#define CRAFT_H

#include <krpc.hpp>
#include <krpc/services/krpc.hpp>
#include <krpc/services/space_center.hpp>

using namespace krpc::services;

namespace douwco {
    class Craft {
        protected:
            SpaceCenter::Vessel vessel;
            double target_lat, target_long;
            
        public: 
            Craft(SpaceCenter::Vessel v, double t_lat, double t_long)
            { 
                vessel = v;
                target_lat = t_lat;
                target_long = t_long; 
            }

            virtual void launch() {};
    };
}


#endif  // CRAFT_H

