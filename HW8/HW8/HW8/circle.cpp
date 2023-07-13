// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "circle.h"

using std::cout;
using std::endl;

//calculate and print area of shape
double circle::get_area()
{
	return 3.14159265359 * twodimensionalshape::get_radius() * twodimensionalshape::get_radius();
}

void circle::print()
{
	cout << "Area = " << get_area() << endl;
}