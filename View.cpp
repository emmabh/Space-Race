#include "View.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Cart_Vector.h"
#include <iomanip>
#include <iostream>

using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	Cart_Point origin(0, 0);
}

void View::clear()
{
	for (int i = 0; i<size; i++){
		for (int j = 0; j<size; j++){
			grid[i][j][0] = '.';
		}
	}

}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	Cart_Vector subCart = location - origin;
	subCart = subCart/scale;

	ix = static_cast<int>(subCart.x);
	iy = static_cast<int>(subCart.y);

	if (ix < size && iy < size){
		return true;
	}else{
		cout << "An object is outside the display" << endl;
		return false;
	}
}

void View::plot(Game_Object *ptr)
{
	int ix, iy;
	bool validPt = get_subscripts(ix, iy, ptr->get_location());

	if (validPt && grid[ix][iy][0] == '.'){
		ptr->drawself(&grid[ix][iy][0]);		//Array indexing is a ptr
	}else if (validPt){
		grid[ix][iy][0] = '*';
		grid[ix][iy][1] = ' ';
	}
}

void View::draw()
{
	for(int j = size-1; j>=0; j--){
		if (j%2 == 0){
			cout << left << setw(2) << (j*4/scale); //Print y axis
		}
		else{
			cout << left << setw(2) << " ";
		}

		//Printing the points on the board
		for(int i = 0; i<size; i++){

			if(grid[i][j][0] != '.'){
				cout << right << grid[i][j][0] << right << grid[i][j][1];
			}else{
				cout << left << setw(2) << grid[i][j][0];
			}
		}
		cout << endl;
	}
	//Print x axis
	for(int k = 0; k<size; k++){
		if(k == 0){
			cout << left << setw(2) << " " << setw(2) << "0";
		}else if (k%2 == 0){
			cout << left << setw(2) << k*4/scale;
		}else{
			cout << left << setw(2) << " ";
		}
	}
	 cout << endl;

	//use format settings for axes, two characters for each numeric value of the axis labels with no decimal pts. 
}
