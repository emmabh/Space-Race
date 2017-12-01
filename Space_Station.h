#ifndef SPACE_STATION_H
#define SPACE_STATION_H
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Person.h"


class Space_Station : public Game_Object
{
	public:
		Space_Station();
		~Space_Station();
		Space_Station(Cart_Point, int);
		void deposit_moonstones(double);
		bool add_astronaut();
		int get_astronauts();
		bool update();
		void show_status();
		friend class Astronaut;

	private:
		double amount_moonstones;
		int number_astronauts;
};

#endif