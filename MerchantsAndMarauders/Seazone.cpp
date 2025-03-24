#include "Seazone.h"

namespace eminem {
	namespace board {
		Seazone::Seazone(const std::string& name) : Location(name) {}//, port(std::nullopt) {}
		Seazone::Seazone(const std::string& name, Nationality portNation) : Location(name) {
			port = std::make_shared<Port>(portNation, name);
		}

		Seazone::~Seazone() {}

		void Seazone::addAdjacent(const Direction dir, const std::shared_ptr<Seazone> adj) {
			adjacent.emplace(std::make_pair(dir, adj));
		}

		//bool Seazone::operator==(const Location& s) const {
		bool Seazone::operator==(const Seazone& s) const {
			return getName() == s.getName();
		}
	}
}

