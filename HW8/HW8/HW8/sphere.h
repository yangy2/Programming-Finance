// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "threedimensionalshape.h"

class sphere : public threedimensionalshape
{
public:
	//calculate and print area and volume of shape
	double get_area();
	double get_volume();
	void print();
};
#endif