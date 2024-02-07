#ifndef BULLET_AUTOPILOT
#define BULLET_AUTOPILOT

#include <krpc.hpp>
#include <krpc/services/krpc.hpp>
#include <krpc/services/space_center.hpp>

using namespace krpc::services;

namespace douwco {
    class BulletAutopilot {
        private:
            SpaceCenter::Vessel vessel;
            
        public: 
            BulletAutopilot(SpaceCenter::Vessel v);

            void start_launch_sequence();
            void run_flight_autopilot();
    };
}


#endif  // BULLET_AUTOPILOT

