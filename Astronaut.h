#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"


#ifndef ASTRONAUT_H
#define ASTRONAUT_H

class Astronaut: public Person
{
public:
	Astronaut();
	~Astronaut();
	Astronaut(int, Cart_Point);
	bool update();
	void start_supplying(Oxygen_Depot*);
	void start_depositing(Space_Station*);
	void go_to_station(Space_Station*);
	void show_status();

private:
	double amount_moonstones;
	double amount_oxygen;
	Oxygen_Depot* depot;
	Space_Station* home;
};

#endif