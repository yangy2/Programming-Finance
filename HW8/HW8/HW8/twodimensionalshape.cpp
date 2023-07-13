// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "twodimensionalshape.h"

//specify shape traits
void twodimensionalshape::set_radius(double input)
{
	radius = input;
}

void twodimensionalshape::set_length(double input)
{
	length = input;
}

//return shape traits
double twodimensionalshape::get_radius()
{
	return radius;
}

//shape traits
double twodimensionalshape::get_length()
{
	return length;
}