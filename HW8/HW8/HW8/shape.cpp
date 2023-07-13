// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "shape.h"

//specify x and y coordinates
void shape::set_x(int input)
{
	x = input;
}

void shape::set_y(int input)
{
	y = input;
}

//return x and y coordinates
int shape::get_x()
{
	return x;
}

int shape::get_y()
{
	return y;
}