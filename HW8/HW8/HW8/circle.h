// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "twodimensionalshape.h"

class circle : public twodimensionalshape
{
public:
	//calculate and print area of shape
	double get_area();
	void print();
};
#endif