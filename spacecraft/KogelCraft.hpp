#ifndef KOGELCRAFT_H
#define KOGELCRAFT_H

#include <krpc.hpp>
#include <krpc/services/krpc.hpp>
#include <krpc/services/space_center.hpp>

#include "Craft.hpp"

using namespace krpc::services;

namespace douwco {
    class KogelCraft : Craft {
        public: 
        KogelCraft(SpaceCenter::Vessel v, double la, double lo): Craft(v, la, lo) {}
        void launch() override;
    };
}


#endif  // KOGELCRAFT_H

