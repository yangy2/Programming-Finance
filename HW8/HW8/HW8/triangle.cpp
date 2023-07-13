// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "triangle.h"

using std::cout;
using std::endl;

//calculate and print area of shape
double triangle::get_area()
{
	return 0.43301270189 * twodimensionalshape::get_length() * twodimensionalshape::get_length();
}

void triangle::print()
{
	cout << "Area = " << get_area() << endl;
}