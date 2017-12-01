#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Person.h"
#include "Space_Station.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Model.h"
#include "Astronaut.h"
#include "View.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

	//for copy constructor??

Model::Model()
{
	time = 0;
	count_down = 10;
	Cart_Point loc1(5,1);
	Cart_Point loc2(10,1);
	Cart_Point loc3(1,20);
	Cart_Point loc4(10,20);
	Cart_Point loc5(5,5);

	Astronaut *Astronaut1 = new Astronaut(1, loc1);
	object__ptrs[0] = Astronaut1;
	person_ptrs[0] = Astronaut1;

	Astronaut *Astronaut2 = new Astronaut(2, loc2);
	object__ptrs[1] = Astronaut2;
	person_ptrs[1] = Astronaut2;
	
	Oxygen_Depot *Oxygen_Depot1 = new Oxygen_Depot(loc3, 1);
	object__ptrs[2] = Oxygen_Depot1;
	depot__ptrs[0] = Oxygen_Depot1;

	Oxygen_Depot *Oxygen_Depot2 = new Oxygen_Depot(loc4, 2);
	object__ptrs[3] = Oxygen_Depot2;
	depot__ptrs[1] = Oxygen_Depot2;

	Space_Station *Space_Station1 = new Space_Station();
	object__ptrs[4] = Space_Station1;
	station_ptrs[0] = Space_Station1;

	Space_Station *Space_Station2 = new Space_Station(loc5, 2);
	object__ptrs[5] = Space_Station2;
	station_ptrs[1] = Space_Station2;

	num_objects = 6;
	num_persons = 2;
	num__depots = 2;
	num_stations = 2;

	cout << "Model default constructed." << endl;

}

Model::~Model()
{
	 for (int i=0; i<num_objects; i++)
	 {
	 	delete object__ptrs[i];
	 }

	cout << "Model destructed." << endl;
}

Person * Model::get_Person_ptr(int id)
{
	for (int i=0; i<num_persons; i++)
	{
		if (person_ptrs[i]->get_id() == id)
		{
			return person_ptrs[i];
		}
	}

	return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
	for (int i=0; i<num__depots; i++)
	{
		if (depot__ptrs[i]->get_id() == id)
		{
			return depot__ptrs[i];
		}
	}

	return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
	for (int i=0; i<num_stations; i++)
	{
		if (station_ptrs[i]->get_id() == id)
		{
			return station_ptrs[i];
		}
	}

	return 0;
}

bool Model::update()
{
	time++;
	bool result = false;
	bool allUpgraded = true;

	//Check to see if station is upgraded
	for(int i = 0; i<num_stations; i++){

		if (station_ptrs[i]->get_state() != 'u'){
			allUpgraded = false;
			break;
		}
		else{
			allUpgraded = true;
			continue;
		}
	}

	//This boolean will eventually tell us if we're ready for takeoff
	bool takeoffReady = true;
	int numAstronauts;
	//Check to see if each station has an astronaut
	for (int i = 0; i < num_stations; i++){
		numAstronauts = station_ptrs[i]->get_astronauts();

		if(numAstronauts == 0){
			takeoffReady = false;
			break;
		}
	}

	//Check to see if each astronaut is at a station
	for (int i = 0; i< num_persons; i++){
		//See if each person is locked into a station
		char state = person_ptrs[i]->get_state();

		if (state != 'l'){
			takeoffReady = false;
			break;
		}
	}

	//Updates every object if it isn't the end of the game
	if (!takeoffReady){

		if(count_down !=0){

			//If all stations are upgraded, then the countdown starts to decrement
			if(allUpgraded){
				cout << "Ready for takeoff? " << count_down << "..." << endl;

				int numLocked = 0;						//number of astronauts locked in
				for (int i = 0; i<num_stations; i++){
					numLocked += station_ptrs[i]->get_astronauts();
				}

				//Number missing
				if(numAstronauts < num_stations){
					cout << "Missing " << num_stations-numLocked << " astronauts!" << endl;
				} 
				
				count_down--;
			}

			//Update all objects
			for (int i = 0; i<num_objects; i++){
				bool truth = object__ptrs[i]->update();

				//returns true if any of the game object update functions return true
				if (truth){
					result = true;
				}
			}
			return result;

		}else{
			//Quits game
			cout << "Unmanned takeoff... You lose!" << endl;
			exit(0);
		}

	}else{
			//Quits game
			cout << "Ready for takeoff? " << count_down << "..." << endl;
			cout << "Blast Off! You Win!" << endl;
			exit(0);
		}
}

 void Model::display(View &view)
 {
	//outputs time and generates view display
	view.clear();
	for (int i = 0; i<num_objects; i++)
	{
		view.plot(object__ptrs[i]);
	}

	view.draw();
 }

void Model::show_status()
{
	cout << "Time: " << time << endl;
	for (int i = 0; i<num_objects; i++){
		object__ptrs[i]->show_status();

	}
}

//copy constructor private
// Model::Model(const Model &obj)
// {

// }

