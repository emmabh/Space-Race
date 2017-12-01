#include "Oxygen_Depot.h"
#include "Game_Object.h"
#include "Cart_Point.h"

#include <iostream>
using namespace std;

Oxygen_Depot:: Oxygen_Depot():Game_Object('O')
{
	state = 'f';
	cout << "Oxygen_Depot default constructed." << endl;
	amount_oxygen = 50;
}	

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId):Game_Object('O')
{
	id_num = inputId;
	location = inputLoc;
	amount_oxygen = 50;
	display_code = 'O';
	state = 'f';
	cout << "Oxygen_Depot constructed." << endl;
}

bool Oxygen_Depot::is_empty()
{
	if (amount_oxygen == 0){
		return true;

	}else{
		return false;
	}
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	//If the amount they want to extract is greater than the amount the depot has, just deplete
	if (amount_oxygen >= amount_to_extract){
		amount_oxygen -= amount_to_extract;
		return amount_to_extract;
	}else{
		amount_oxygen = 0;
		return amount_oxygen;
	}
}

//Default extraction
double Oxygen_Depot::extract_oxygen()
{
	double amount_to_extract = 20;
	if (this->amount_oxygen >= amount_to_extract){
		amount_oxygen -= amount_to_extract;
		return amount_to_extract;
	}else{
		amount_oxygen = 0;
		return amount_oxygen;
	}
}

bool Oxygen_Depot::update()
{
	if (amount_oxygen == 0 && state != 'e'){
		state = 'e';
		display_code = 'o';
		cout << "Oxygen_Depot " << id_num << " has been depleted." << endl;
		return true;
	}else{
		return false;
	}
}

void Oxygen_Depot::show_status()
{
	cout << "Oxygen Depot status: ";
	Game_Object::show_status();
	cout << " contains " << amount_oxygen << "." << endl;
}

Oxygen_Depot::~Oxygen_Depot()
{
	cout << "Oxygen_Depot destructed." << endl;
}