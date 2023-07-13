// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef TETRAHEDRON_h
#define TETRAHEDRON_H

#include <iostream>
#include "threedimensionalshape.h"

class tetrahedron : public threedimensionalshape
{
public:
	//calculate and print area and volume of shape
	double get_area();
	double get_volume();
	void print();
};
#endif