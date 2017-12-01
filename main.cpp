#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Astronaut.h"
#include "Game_Command.h"
#include "Model.h"
#include "View.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "EC327: Introduction to Software Engineering" << endl << "Fall 2017" << endl << "Programming Assingment 3" << endl;
	View NewView;
	Model NewMod;
	char command;
	int ID1, ID2, ID3, ID4, id_num;
	double m1, m2;


	NewMod.show_status();
	NewMod.display(NewView);

	do{
		cout << "Enter command: ";
		cin >> command;

	//Has different inputs for each command, and checks to see if they fail to avoid seg fault
	switch(command){
		case 'm': cin >> id_num >> m1 >> m2;
					if(cin.fail()){
						cout << "ERROR: Please enter valid command!" << endl;
						cin.clear();
						break;
					}else{
						do_move_command(NewMod, id_num, m1, m2);
						NewMod.display(NewView);                 //echoes command in itself & outputs display
						break;
					}
		case 'w': 	cin >> ID1 >> ID2;					//echoes in command itself
					if(cin.fail()){
						cout << "ERROR: Please enter valid command!" << endl;
						cin.clear();
						break;
					}else{
	 					do_work_command(NewMod, ID1, ID2);
	 					NewMod.display(NewView); 			//output display
						break;
					}
		case 'd': cin >> ID3 >> ID4;					//echoes in command itself
					if(cin.fail()){
						cout << "ERROR: Please enter valid command!" << endl;
						cin.clear();
						break;
					}else{
					do_deposit_command(NewMod, ID3, ID4);
					NewMod.display(NewView);				//output display
					break;
					}
		case 's': cin >> ID1;
					if(cin.fail()){
						cout << "ERROR: Please enter valid command!" << endl;
						cin.clear();
						break;
					}else{
						do_stop_command(NewMod, ID1);
						NewMod.display(NewView);		//output display
						break;
					}

		case 'l': cin >> ID1 >> ID2;
					if(cin.fail()){
						cout << "ERROR: Please enter valid command!" << endl;
						cin.clear();
						break;
					}else{
						do_lock_command(NewMod, ID1, ID2);
						NewMod.display(NewView);			//output display
						break;
					}

		case 'g': 	cout << "Advancing one tick." << endl; 
					do_go_command(NewMod);
					NewMod.show_status();					 //If command is 'g', shows status
					NewMod.display(NewView);				//output display
					break;

		case 'r':	cout << "Advancing to next event." << endl;
					do_run_command(NewMod);
					NewMod.show_status();					//If command is 'r', shows status
					NewMod.display(NewView);				//output display
					break;

		case 'q': 	cout << "Terminating program."<< endl;
					do_quit_command(NewMod);
					break;

		default: cout << "ERROR: Please enter a valid command!" << endl;
					break;

	}

	}while(command != 'q');

	return 0;
}