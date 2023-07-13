//Yilin Yang
//Programming Finance HW7

#pragma once
#ifndef polynomial_h
#define polynomial_h
#define size 13
#include<iostream>

using std::ostream;

class polynomial
{
	friend ostream &operator<<(ostream&, const polynomial p);

public:
	int terms;
	int P[size] = { 0 };

	void refresh_cin();

	void getdata();
	void setdata(int, int);

	void operator=(polynomial);

	polynomial operator+(polynomial);
	polynomial operator-(polynomial);
	polynomial operator*(polynomial);
	polynomial operator+=(polynomial);
	polynomial operator-=(polynomial);
	polynomial operator*=(polynomial);

};

#endif
