// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "twodimensionalshape.h"

class triangle : public twodimensionalshape
{
public:
	//calculate and print area of shape
	double get_area();
	void print();
};
#endif