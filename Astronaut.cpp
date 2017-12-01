#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"

#include "Astronaut.h"

#include <iostream>
using namespace std;

Astronaut::Astronaut():Person('A')
{
	amount_moonstones = 0;
	amount_oxygen = 50;
	depot = NULL;
	home = NULL;								

	cout << "Astronaut default constructed." << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc):Person(in_loc, in_id, 'A')
{
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;

	cout << "Astronaut constructed." << endl;
}

bool Astronaut::update()
{

	switch(state){
		case 's': {return false;
					break;}
		case 'm': {
					if(amount_oxygen == 0){
						this->state = 'l';
						cout << "I can't move, I'm out of oxygen." << endl;
						return true;
					}else if(update_location()){
						this->state = 's';
						return true;
					}else{
						amount_oxygen--;
						amount_moonstones++;
						return false;
					}
					break;}
		case 'o': {
					if(amount_oxygen == 0){
						this->state = 'l';
						cout << "I can't move, I'm out of oxygen." << endl;
						return true;
					}else if (update_location()){
						this->state = 'g';
						return true;
					}else{
						amount_moonstones++;
						amount_oxygen--;
						return false;
					}
				
					break;}
		case 'g': {
					//cout proper message, subtract oxygen from depot and add to astronaut
					double amount_extracted = depot->extract_oxygen();
					cout << display_code << id_num << ": Got " << amount_extracted << " more oxygen." << endl;
					this->state = 's';
					this->amount_oxygen += amount_extracted; 
					return true;
					break;}
		case 'i': {
					if(amount_oxygen == 0){
						this->state = 'l';
						cout << "I can't move, I'm out of oxygen." << endl;
						return true;
					}else if(update_location()){
						this->state = 'd';
						return true;
					}else{
						amount_moonstones++;
						amount_oxygen--;
						return false;
					}
					break;}
		case 'd': {cout << display_code << id_num << ": Deposit " << amount_moonstones << " moonstones." << endl;
					home->deposit_moonstones(amount_moonstones);
					this->amount_moonstones = 0;
					this->state = 's';
					return true;
					break;}
		case 'l': {
					if((location.x != destination.x) && (location.y != destination.y)){
						if(update_location()){			
							home->add_astronaut();
							return true;
						}else{
							amount_moonstones++;
							amount_oxygen--;
							return false;
						}
					}else{
						return false;
					}
					break;}
	}

}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
	cout << "Astronaut " << id_num << " supplying at Oxygen Depot " << inputDepot->id_num << "." << endl;

	//Make sure astronaut isn't locked in, then perform
	if(state != 'l'){
		depot = inputDepot;
		setup_destination((inputDepot->location));
		state = 'o';
		cout << display_code << id_num << ": Yes, my lord." << endl;
	}else{
		cout << "I can't supply, I'm locked in." << endl;
	}
}

void Astronaut::start_depositing(Space_Station* inputStation)
{
	cout << "Astronaut " << id_num << " depositing at Space Station " << inputStation->id_num << "." << endl;

	//Make sure astronaut isn't locked in, then perform
	if(state != 'l'){
		state = 'i';
		setup_destination((inputStation->location));
		this->home = inputStation;
		cout << display_code << id_num << ": Yes, my lord." << endl;
	}else{
		cout << "I can't deposit, I'm locked in." << endl;
	}


}

void Astronaut::go_to_station(Space_Station* inputStation)
{
	state = 'l';
	this->home = inputStation;
	cout << "Astronaut " << id_num << " locking in at Space_Station " << home->id_num << endl;
	setup_destination(home->location);
}

void Astronaut::show_status()
{
	cout << "Astronaut status: ";
	Person::show_status();

	switch (state){
		case 's': 	cout << " with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
					break;
		case 'm': 	cout << endl;
					break;
		case 'o': 	cout << " is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
					break;
		case 'g': 	cout << " is getting oxygen from Depot." << endl;
					break;
		case 'i': 	cout << " is inbound to home with load: " << amount_moonstones << " and " << amount_oxygen << " oxygen." << endl;
					break;
		case 'd': 	cout << " is depositing " << amount_moonstones << " moon stones." << endl;
					break;
		case 'l':	if (this->amount_oxygen == 0){
						cout << " . Out of oxygen." << endl;
					}else{
						cout << " at Space Station." << endl;
					}
					break;
	}

}

Astronaut::~Astronaut()
{
	cout << "Astronaut destructed." << endl;
}