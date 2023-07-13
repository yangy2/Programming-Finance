// Yilin Yang
// Programming Finance HW 8

#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>

class shape
{
public:

	//specify x and y coordinates
	void set_x(int);
	void set_y(int);

	//return x and y coordinates
	int get_x();
	int get_y();

private:
	//x and y coordinates
	int x;
	int y;
};
#endif