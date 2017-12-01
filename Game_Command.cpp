#include <iostream>
using namespace std;

#include "Game_Command.h"
#include "Model.h"
#include "Astronaut.h"
#include "Person.h"

//For running, we use this counter in the astronaut update as well
int runCount = 0;

void do_move_command(Model &model, int id_num, double x, double y)
{
	Astronaut *Astronaut1 = dynamic_cast<Astronaut*>(model.get_Person_ptr(id_num));

	Cart_Point newpt(x, y);
	Astronaut1->start_moving(newpt);
}

void do_work_command(Model &model, int ID1, int ID2)
{
	Astronaut *astronaut2 = dynamic_cast<Astronaut*>(model.get_Person_ptr(ID1));
	Oxygen_Depot *depot2 = model.get_Oxygen_Depot_ptr(ID2);

		astronaut2->start_supplying(depot2);

}

void do_deposit_command(Model &model, int ID1, int ID2)
{
	Astronaut *astronaut3 = dynamic_cast<Astronaut*>(model.get_Person_ptr(ID1));
	Space_Station *station3 = model.get_Space_Station_ptr(ID2);

	astronaut3->start_depositing(station3);
}

void do_stop_command(Model &model, int ID)
{
	Astronaut *astronaut4 = dynamic_cast<Astronaut*>(model.get_Person_ptr(ID));

	astronaut4->stop();
	
}

void do_lock_command(Model &model, int ID1, int ID2)
{
	Astronaut *astronaut5 = dynamic_cast<Astronaut*>(model.get_Person_ptr(ID1));
	Space_Station *station5 = model.get_Space_Station_ptr(ID2);

	astronaut5->go_to_station(station5);

}

void do_go_command(Model &model)
{
	model.update();

}

void do_run_command(Model &model)
{	
	bool updateStat = false;
	
	while(runCount < 5 && !updateStat){
		updateStat = model.update();
		runCount++;
	}

	runCount = 0;
}

void do_quit_command(Model &model)
{
	//returns back to program and destructors 
}

