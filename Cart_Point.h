#include<iostream>
using namespace std;
#include "Cart_Vector.h"

#ifndef CART_POINT_H
#define CART_POINT_H

class Cart_Point
{
 public:
  double x;
  double y;
  Cart_Point();
  Cart_Point(double, double);
};

ostream& operator << (ostream& out, Cart_Point &p1);

Cart_Point operator + (Cart_Point &p1, Cart_Point &p2);

Cart_Vector operator - (Cart_Point &p1, Cart_Point &p2);

double cart_distance(Cart_Point p1, Cart_Point p2);
#endif	
