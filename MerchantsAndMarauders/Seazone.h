#pragma once
#include <memory>
#include <map>
#include <string>
#include "Port.h"
#include <optional>

namespace eminem {
	namespace board {
		enum Direction {
			N, NE, E, SE, S, SW, W, NW
		};

		inline Direction opposite(Direction d) { return static_cast<Direction>((static_cast<int>(d) + 4) % 8); }

		class Seazone : public Location
		{
		public:
			Seazone(const std::string& name, Nationality portNation);
			Seazone(const std::string& name);

			~Seazone() override;

			void addAdjacent(const Direction dir, const std::shared_ptr<Seazone> adj);
			std::shared_ptr<Port> getPort() const { return port; }
			bool hasPort() const { return true; }// port.has_value(); }
			std::map<Direction, std::shared_ptr<Seazone>>& getAdjacents() { return adjacent; }
			std::shared_ptr<Seazone>& getAdjacent(const Direction& dir) { return adjacent[dir]; }

			//bool operator==(const Location&) const;
			bool operator==(const Seazone&) const;

		private:			
			std::shared_ptr<Port> port;
			std::map<Direction, std::shared_ptr<Seazone>> adjacent;
		};

	}
}