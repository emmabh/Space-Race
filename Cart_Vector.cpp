#include "Cart_Vector.h"
#include <iostream>

using namespace std;

Cart_Vector::Cart_Vector()
{
  x = 0;
  y = 0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
  x = inputx;
  y = inputy;

}

Cart_Vector operator * (Cart_Vector &v1, double d)
{
  return Cart_Vector((v1.x*d), (v1.y*d));
}

Cart_Vector operator / (Cart_Vector &v1, double d)
{
  if (d == 0)
    return v1;
  else
    return Cart_Vector((v1.x/d), (v1.y/d));
}

ostream& operator <<(ostream& out, Cart_Vector &v1)
{
  out << "<" << v1.x << ", " << v1.y << ">";
  return out;
}

