#pragma once
#include <memory>
#include <map>
#include <string>
#include "Port.h"

namespace eminem {
	namespace board {
		enum class Direction {
			N, NE, E, SE, S, SW, W, NW
		};

		Direction opposite(Direction d) { return static_cast<Direction>((static_cast<int>(d) + 4) % 8); }

		class Seazone : public Location
		{
		public:
			Seazone(const std::string& name, Nationality portNation);
			Seazone(const std::string& name);

			~Seazone() override;

			void addAdjacent(const Direction dir, const std::shared_ptr<Seazone> adj);
			//std::shared_ptr<Port> getPort() const { return port; }
			bool hasPort() const { return _hasPort; }
			std::map<Direction, std::shared_ptr<Seazone>>& getAdjacents() { return adjacent; }

			//bool operator==(const Location&) const;
			bool operator==(const Seazone&) const;

		private:			
			//std::shared_ptr<Port> port;
			bool _hasPort;
			std::map<Direction, std::shared_ptr<Seazone>> adjacent;
		};

	}
}