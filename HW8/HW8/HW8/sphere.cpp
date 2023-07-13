// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "sphere.h"

using std::cout;
using std::endl;

//calculate and print area and volume of shape
double sphere::get_area()
{
	return 4 * 3.14159265359 * threedimensionalshape::get_radius() * threedimensionalshape::get_radius();
}

double sphere::get_volume()
{
	return (4 * 3.14159265359 * threedimensionalshape::get_radius() 
		* threedimensionalshape::get_radius() * threedimensionalshape::get_radius())/3;
}

void sphere::print()
{
	cout << "Area = " << get_area() << endl;
	cout << "Volume = " << get_volume() << endl;
	
}