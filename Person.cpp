#include "Person.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include <math.h>

#include <iostream>
using namespace std;

Person::Person():Game_Object('P')
{
	speed = 5;
	cout << "Person default constructed." << endl;
}

Person::Person(char in_code):Game_Object(in_code)
{
	speed = 5;
	state = 's';
	display_code = in_code;
	cout << "Person constructed." << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)
{
	speed = 5;
	cout << "Person constructed." << endl;
}

void Person::start_moving(Cart_Point dest)
{
	cout << "Moving " << id_num << " to " << dest << "." << endl;
	//if person is locked in, don't start moving.
	if(state != 'l'){
		//If person is already at the destination, don't do anything.
		if (dest.x == location.x && dest.y == location.y){
			cout << display_code << id_num << ": I'm already there. See?" << endl;
		}else{
			state = 'm';
			this->setup_destination(dest);
			cout << display_code << id_num << ": On my way." << endl;
		}
	}else{
		cout << "I can't move, I'm locked in." << endl;
	}
}

void Person::stop()
{
	cout << display_code << id_num << ": Stopped." << endl;

	//If person is locked in, cannot change to stopped
	if(state != 'l'){
		state = 's';
	}else{
		cout << "I can't stop, I'm locked in." << endl;
	}
}

void Person::show_status()
{
	Game_Object::show_status();

	if (state == 's'){
		cout << " is stopped";
	}else if(state == 'l'){
		cout << " is locked";
	}else{
		cout << " moving at speed of " << speed << " towards " << destination << " at each step of " << delta;	
	}
}

bool Person::update_location()
{
	if (fabs((destination-location).x) <= fabs(delta.x) && fabs((destination-location).y) <=fabs(delta.y)){ //if the astronaut has arrived at destination
		location = destination;
		cout << display_code << id_num << ": I'm there!" << endl; 
		return true;
	}else{
		cout << display_code << id_num << ": step..." << endl;
		this->location.x = location.x + delta.x;
		this->location.y = location.y + delta.y;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest)
{
	//sets up object to move to dest
	Cart_Vector dist = (dest - location);
	this->delta = dist * (speed/cart_distance(dest,location));
	this->destination = dest;
}

Person::~Person()
{
	cout << "Person destructed." << endl;
}

void Person::start_supplying()
{
	cout << "Sorry, I can't work a depot." << endl;
}

void Person::start_depositing()
{
	cout << "Sorry, I can't work a station." << endl;
}

void Person::go_to_station()
{
	cout << "Sorry, I can't lock into a station." << endl;
}
