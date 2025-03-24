#pragma once

#include "Location.h"

namespace eminem {
	namespace board {
		class Location;

		enum class Nationality
		{
			ENGLISH, DUTCH, FRENCH, SPANISH
		};

		class Port : public Location
		{
		public:
			Port(Nationality n, std::string& zone_name) : Location("Port - " + zone_name), nationality(n) {}//, seazone(s) {}

			~Port() override;

			//Seazone* getSeazone() { return seazone; }

			bool operator==(const Port&) const;
		private:
			Nationality nationality;
			//Seazone* seazone;
		};

	}
}