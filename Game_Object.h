#include "Cart_Point.h"
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


class Game_Object
{
	public:
		virtual ~Game_Object();
		Game_Object(char);
		Game_Object(Cart_Point, int, char);
		Cart_Point get_location();
		int get_id();
		char get_state();
		virtual bool update();
		virtual void show_status();
		void drawself(char*);

	protected:
		Cart_Point location;
		int id_num;
		char display_code;
		char state;
};

#endif