#include "Port.h"

namespace eminem {
	namespace board {
		Port::~Port() {}
		bool Port::operator==(const Port& p) const
		{
			return getName() == p.getName();
		}
	}
}