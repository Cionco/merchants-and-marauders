#include "Board.h"

namespace eminem {
	namespace board {
		void eminem::board::Board::setupBoard()
		{
			tiles.emplace(HAVANA, std::make_shared<Seazone>(HAVANA, Nationality::SPANISH));
			tiles.emplace(PORT_ROYAL, std::make_shared<Seazone>(PORT_ROYAL, Nationality::ENGLISH));
			tiles.emplace(OLD_PROVIDENCE, std::make_shared<Seazone>(OLD_PROVIDENCE, Nationality::ENGLISH));
			tiles.emplace(NASSAU, std::make_shared<Seazone>(NASSAU, Nationality::ENGLISH));
			tiles.emplace(TORTUGA, std::make_shared<Seazone>(TORTUGA, Nationality::FRENCH));
			tiles.emplace(PETITE_GOARE, std::make_shared<Seazone>(PETITE_GOARE, Nationality::FRENCH));
			tiles.emplace(CARTAGENA, std::make_shared<Seazone>(CARTAGENA, Nationality::SPANISH));
			tiles.emplace(SANTO_DOMINGO, std::make_shared<Seazone>(SANTO_DOMINGO, Nationality::SPANISH));
			tiles.emplace(THE_CARIBBEAN_SEA, std::make_shared<Seazone>(THE_CARIBBEAN_SEA));
			tiles.emplace(CURACAO, std::make_shared<Seazone>(CURACAO, Nationality::DUTCH));
			tiles.emplace(SAN_JUAN, std::make_shared<Seazone>(SAN_JUAN, Nationality::SPANISH));
			tiles.emplace(CARACAS, std::make_shared<Seazone>(CARACAS, Nationality::SPANISH));
			tiles.emplace(ST_MAARTEN, std::make_shared<Seazone>(ST_MAARTEN, Nationality::DUTCH));

			link_tiles(NASSAU, HAVANA, Direction::SW);
			link_tiles(NASSAU, TORTUGA, Direction::SE);
			link_tiles(HAVANA, PORT_ROYAL, Direction::S);
			link_tiles(HAVANA, TORTUGA, Direction::E);
			link_tiles(PORT_ROYAL, OLD_PROVIDENCE, Direction::S);
			link_tiles(PORT_ROYAL, TORTUGA, Direction::NE);
			link_tiles(PORT_ROYAL, PETITE_GOARE, Direction::E);
			link_tiles(PORT_ROYAL, CARTAGENA, Direction::SE);
			link_tiles(OLD_PROVIDENCE, CARTAGENA, Direction::E);
			link_tiles(TORTUGA, PETITE_GOARE, Direction::S);
			link_tiles(TORTUGA, SANTO_DOMINGO, Direction::SE);
			link_tiles(PETITE_GOARE, SANTO_DOMINGO, Direction::E);
			link_tiles(PETITE_GOARE, THE_CARIBBEAN_SEA, Direction::SE);
			link_tiles(PETITE_GOARE, CARTAGENA, Direction::S);
			link_tiles(CARTAGENA, THE_CARIBBEAN_SEA, Direction::NE);
			link_tiles(CARTAGENA, CURACAO, Direction::E);
			link_tiles(SANTO_DOMINGO, SAN_JUAN, Direction::E);
			link_tiles(SANTO_DOMINGO, THE_CARIBBEAN_SEA, Direction::S);
			link_tiles(THE_CARIBBEAN_SEA, SAN_JUAN, Direction::NE);
			link_tiles(THE_CARIBBEAN_SEA, BASSE_TERRE, Direction::E);
			link_tiles(THE_CARIBBEAN_SEA, CARACAS, Direction::SE);
			link_tiles(THE_CARIBBEAN_SEA, CURACAO, Direction::S);
			link_tiles(CURACAO, CARACAS, Direction::E);
			link_tiles(SAN_JUAN, ST_MAARTEN, Direction::E);
			link_tiles(SAN_JUAN, BASSE_TERRE, Direction::SE);
			link_tiles(CARACAS, BASSE_TERRE, Direction::NE);
			link_tiles(CARACAS, TRINIDAD, Direction::E);
			link_tiles(ST_MAARTEN, ST_JOHN, Direction::E);
			link_tiles(ST_MAARTEN, BASSE_TERRE, Direction::S);
			link_tiles(BASSE_TERRE, ST_JOHN, Direction::NE);
			link_tiles(BASSE_TERRE, BRIDGETOWN, Direction::E);
			link_tiles(BASSE_TERRE, TRINIDAD, Direction::S);
			link_tiles(TRINIDAD, BRIDGETOWN, Direction::NE);
			link_tiles(ST_JOHN, BRIDGETOWN, Direction::S);

		}
		void Board::link_tiles(const std::string& name1, const std::string& name2, Direction dir)
		{
			tiles[name1]->addAdjacent(dir, tiles[name2]);
			tiles[name2]->addAdjacent(opposite(dir), tiles[name1]);
		}
	}
}
