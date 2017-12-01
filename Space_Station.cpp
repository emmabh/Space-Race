#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include <iostream>

using namespace std;

Space_Station::Space_Station():Game_Object('s')
{
	id_num = 1;
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station default constructed." << endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId):Game_Object('S')
{
	id_num = inputId;
	location = inputLoc;
	display_code = 's';
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;

	cout << "Space_Station constructed." << endl;
}
void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones += deposit_amount;
}

bool Space_Station::add_astronaut()
{
	if (state == 'u')
	{
		number_astronauts++;
		return true;
	}else{
		return false;
	}
}

int Space_Station::get_astronauts()
{
	return number_astronauts;
}

bool Space_Station::update()
{
	if (amount_moonstones >= 10 && display_code != 'S' )
	{
		state = 'u';
		display_code = 'S';
		cout << display_code << id_num << " has been upgraded." << endl;
		return true;
	}else{
		return false;
	}

}

void Space_Station::show_status()
{
	cout << "Space Station status: ";
	Game_Object::show_status(); 
	cout << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts.";
	if (state == 'u'){
		cout << " Upgraded." << endl;
	}else{
		cout << " Not yet upgraded." << endl;
	}

	
}

Space_Station::~Space_Station()
{
	cout << "Space_Station destructed." << endl;
}