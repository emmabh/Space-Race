#include<iostream>
using namespace std;
#ifndef CART_VECTOR_H
#define CART_VECTOR_H

class Cart_Vector
{
 public:
  double x;
  double y;
  
  Cart_Vector();
  Cart_Vector(double inputx, double inputy);
};

Cart_Vector operator * (Cart_Vector &v1, double d);

Cart_Vector operator / (Cart_Vector &v1, double d);

ostream& operator <<(ostream& out, Cart_Vector &v1);

#endif
