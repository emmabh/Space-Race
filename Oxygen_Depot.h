#include "Game_Object.h"
#include "Cart_Point.h"
#include "Person.h"

#ifndef OXYGEN_DEPOT_H
#define OXYGEN_DEPOT_H

class Oxygen_Depot : public Game_Object
{
public:
	Oxygen_Depot();
	~Oxygen_Depot();
	Oxygen_Depot(Cart_Point, int);
	bool is_empty();
	double extract_oxygen(double);
	double extract_oxygen();
	bool update();
	void show_status();
	friend class Astronaut;

private:
	double amount_oxygen;
};

#endif