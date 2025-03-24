#include "Captain.h"
#include "Seazone.h"
#include "Port.h"

namespace eminem {
    namespace entity {
        //bool eminem::entity::Captain::move(std::shared_ptr<board::Location> target)
        bool eminem::entity::Captain::move(std::shared_ptr<board::Seazone> target)
        {
            
            //std::shared_ptr<board::Seazone> loc = dynamic_pointer_cast<board::Seazone>(currentLocation);
            for (auto& p : currentLocation->getAdjacents()) {
                if (*(p.second) == *target) {
                    currentLocation = target;
                    return true;
                }
            }
            return false;
        }

        bool Captain::enterOrExitPort() {
            //if (!inPort && dynamic_pointer_cast<board::Seazone>(currentLocation)->hasPort()) {
            if (!inPort && currentLocation->hasPort()) {
                inPort = true;
                return true;
            }
            else if (inPort) {
                inPort = false;
                return false;
            }
            return false;
        }
    }
}
