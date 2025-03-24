#pragma once
#include <cstdint>
#include <memory>

namespace eminem {
	namespace entity {
		class Ship
		{
		public:
			Ship(uint8_t tough, uint8_t cargo, uint8_t crew, uint8_t cannons, uint8_t maneuver) : toughness(tough), cargo(cargo), crew(crew), cannons(cannons), maneuverability(maneuver) {}
			~Ship() = default;

		private:
			uint8_t toughness;
			uint8_t cargo;
			uint8_t crew;
			uint8_t cannons;
			uint8_t maneuverability;
		};

		class ShipFactory {
			static std::shared_ptr<Ship> flute() {
				return std::make_shared<Ship>(3, 4, 1, 1, 2);
			}

			static std::shared_ptr<Ship> frigate() {
				return std::make_shared<Ship>(3, 3, 3, 3, 3);
			}

			static std::shared_ptr<Ship> sloop() {
				return std::make_shared<Ship>(2, 2, 2, 1, 4);
			}

		};
	}
}