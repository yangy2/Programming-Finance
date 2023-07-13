// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "tetrahedron.h"

using std::cout;
using std::endl;

//calculate and print area and volume of shape
double tetrahedron::get_area()
{
	return 1.73205080757 * threedimensionalshape::get_length() * threedimensionalshape::get_length();
}

double tetrahedron::get_volume()
{
	return (threedimensionalshape::get_length() * threedimensionalshape::get_length() * threedimensionalshape::get_length()) / 8.48528137424;
}

void tetrahedron::print()
{
	cout << "Area = " << get_area() << endl;
	cout << "Volume = " << get_volume() << endl;

}