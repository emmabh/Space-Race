#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"

#ifndef PERSON_H
#define PERSON_H

class Person: public Game_Object
{
public:
	Person();
	virtual ~Person();
	Person(char);
	Person(Cart_Point, int, char);
	void start_moving(Cart_Point);
	void stop();
	void show_status();
	virtual void start_supplying();
	virtual void start_depositing();
	virtual void go_to_station();
	friend class Astronaut;


protected:
	bool update_location();
	void setup_destination(Cart_Point);

private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
};

#endif