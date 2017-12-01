
#include "View.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Person.h"
#include "Space_Station.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

#ifndef MODEL_H
#define MODEL_H

class Model
{

private:
	int time;
	int count_down;

	Game_Object *object__ptrs[10];
	int num_objects;
	Person* person_ptrs[10];
	int num_persons;
	Oxygen_Depot *depot__ptrs[10];
	int num__depots;
	Space_Station *station_ptrs[10];
	int num_stations;
	Model(const Model &obj);
	//each onject will have a pointer in object ptrs array and other array, eg person
public:
	Model();
	~Model();
	Person *get_Person_ptr(int id);
	Oxygen_Depot *get_Oxygen_Depot_ptr(int id);
	Space_Station *get_Space_Station_ptr(int id);
	bool update();
	void display (View &view);
	void show_status();		
};
#endif