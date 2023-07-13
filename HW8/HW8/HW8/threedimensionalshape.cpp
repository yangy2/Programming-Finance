// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "threedimensionalshape.h"

//z coordinate functionality
void threedimensionalshape::set_z(int input)
{
	z = input;
}

int threedimensionalshape::get_z()
{
	return z;
}

//specify shape traits
void threedimensionalshape::set_radius(double input)
{
	radius = input;
}

void threedimensionalshape::set_length(double input)
{
	length = input;
}

//return shape traits
double threedimensionalshape::get_radius()
{
	return radius;
}

//shape traits
double threedimensionalshape::get_length()
{
	return length;
}