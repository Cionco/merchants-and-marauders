#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include "Seazone.h"
#include "Location.h"
#include <iostream>

namespace eminem {
	namespace entity {
		class Port {};

		class Captain
		{
		public:
			Captain(std::shared_ptr<board::Seazone> initialLocation) : currentLocation(initialLocation) {}

			//bool move(std::shared_ptr<board::Location> target);
			bool move(std::shared_ptr<board::Seazone> target);
			bool enterOrExitPort();

			void printLoc() { 
				std::cout << "Currently in " << currentLocation->getName();
				if (inPort) std::cout << " - Port";
				std::cout << std::endl;
			}

		private:
			uint8_t seamanship;
			uint8_t scouting;
			uint8_t leadership;
			uint8_t influence;

			std::vector<std::string> abilities;
			Port home_port;

			//std::shared_ptr<board::Location> currentLocation;
			std::shared_ptr<board::Seazone> currentLocation;
			bool inPort = false;
		};

	}
}