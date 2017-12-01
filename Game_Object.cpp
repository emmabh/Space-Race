#include "Game_Object.h"
#include "Cart_Point.h"

#include<iostream>
using namespace std;


	Game_Object::Game_Object(char in_code)
	{
		display_code = in_code;
		id_num = 1;
		state = 's';
		cout << "Game_Object constructed." << endl;
	}

	Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
	{
		display_code = in_code;
		id_num = in_id;
		location = in_loc;
		state = 's';

		cout << "Game_Object constructed." << endl;
	}

	Cart_Point Game_Object::get_location()
	{
		return location;
	}

	int Game_Object::get_id()
	{
		return id_num;
	}
	char Game_Object::get_state()
	{
		return state;
	}
	void Game_Object::show_status()
	{
		cout << display_code << id_num << " at " << location;
	}

	Game_Object::~Game_Object()
	{
		cout << "Game_Object destructed." << endl;
	}

	bool Game_Object::update()
	{

	}

	void Game_Object::drawself(char* ptr)
	{
		//Puts display_code at the character pointed to by ptr and then the ASCII char for the id_num next
		*ptr = display_code;
		*(ptr + 1) = static_cast<char>(id_num+'0');
	}

