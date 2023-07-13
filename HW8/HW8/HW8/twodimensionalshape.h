// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include <iostream>
#include "shape.h"

class twodimensionalshape : public shape
{
public:
	//specify shape traits
	void set_radius(double);
	void set_length(double);

	//return shape traits
	double get_radius();
	double get_length();

private:
	//shape traits
	double radius;
	double length;
};
#endif