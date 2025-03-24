#pragma once
#include <string>

namespace eminem {
	namespace board {
		class Location
		{
		public:
			Location() {}
			Location(const std::string& name) : name(name) {}
			virtual ~Location() {}

			const std::string& getName() const {
				return name;
			}

		private:
			std::string name;
		};
	}
}