#pragma once
#include <map>
#include "Seazone.h"
#include <memory>
#include <string>

namespace eminem {
	namespace board {
		const std::string HAVANA = "Havana";
		const std::string PORT_ROYAL = "Port Royal";
		const std::string OLD_PROVIDENCE = "Old Providence";
		const std::string NASSAU = "Nassau";
		const std::string TORTUGA = "Tortuga";
		const std::string PETITE_GOARE = "Petite Goare";
		const std::string CARTAGENA = "Cartagena";
		const std::string SANTO_DOMINGO = "Santo Domingo";
		const std::string THE_CARIBBEAN_SEA = "The Caribbean Sea";
		const std::string CURACAO = "Curacao";
		const std::string SAN_JUAN = "San Juan";
		const std::string CARACAS = "Caracas";
		const std::string ST_MAARTEN = "St. Maarten";
		const std::string BASSE_TERRE = "Basse-Terre";
		const std::string TRINIDAD = "Trinidad";
		const std::string ST_JOHN = "St. John";
		const std::string BRIDGETOWN = "Bridgetown";

		class Board
		{
		public:
			void setupBoard();

			std::shared_ptr<Seazone> getTile(const std::string& name) {
				return tiles[name];
			}

		private:
			/**
			 * Link tiles with the names 1 and 2. Direction indicates where the second tile is relative to the first one
			 */
			void link_tiles(const std::string&, const std::string&, Direction);

			std::map<std::string, std::shared_ptr<Seazone>> tiles;
		};

	}
}

