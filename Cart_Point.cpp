#include "Cart_Point.h"
#include <iostream>
#include "Cart_Vector.h"
#include <math.h>

using namespace std;

Cart_Point::Cart_Point()
  {
    x = 0.0;
    y = 0.0;
  }
  
Cart_Point::Cart_Point(double inputx, double inputy)
  {
    x = inputx;
    y = inputy;
  }

ostream& operator << (ostream& out, Cart_Point &p1)
{
  out << "(" << p1.x << ", " << p1.y << ")";
  return out;
}

Cart_Point operator + (Cart_Point &p1, Cart_Point &p2)
{
  return Cart_Point((p1.x + p2.x), (p1.y + p2.y));
}

Cart_Vector operator - (Cart_Point &p1, Cart_Point &p2)
{
  return Cart_Vector((p1.x - p2.x), (p1.y  - p2.y));
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  
  double distance;
  distance = sqrt(pow(dx, 2)+ pow(dy, 2));
      
  return distance;
}

