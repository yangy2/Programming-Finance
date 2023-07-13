// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include <iostream>
#include "shape.h"

class threedimensionalshape : public shape
{
public:
	//z coordinate functionality
	void set_z(int);
	int get_z();

	//specify shape traits
	void set_radius(double);
	void set_length(double);

	//return shape traits
	double get_radius();
	double get_length();

private:
	//shape traits
	int z;
	double radius;
	double length;
};
#endif