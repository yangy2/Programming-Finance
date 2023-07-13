//Yilin Yang
//Programming Finance HW7

#include <iostream>
#include "polynomial_yilin_yang.h"

using std::cout;
using std::endl;
using std::cin;

void main()
{
	polynomial p1, p2, add1, add2, sub1, sub2, mul1, mul2;

	cout << "Initializing First Polynomial..." << endl;
	p1.getdata();
	cout << "First Polynomial: " << p1 << endl;

	cout << endl;

	cout << "Initializing Second Polynomial..." << endl;
	p2.getdata();
	cout << "Second Polynomial: " << p2 << endl;

	cout << endl;

	cout << "Adding polynomial yields:      ";
	add1 = p1 + p2;
	cout << add1 << endl;
	cout << "+= the polynomial yields:      ";
	add2 = p1;
	add2 += p2;

	cout << endl;

	cout << "Subtracting polynomial yields: ";
	sub1 = p1 - p2;
	cout << sub1 << endl;
	cout << "-= the polynomial yields:      ";
	sub2 = p1;
	sub2 -= p2;

	cout << endl;

	cout << "Multiplying polynomial yields: ";
	mul1 = p1 * p2;
	cout << mul1 << endl;
	cout << "*= the polynomial yields:      ";
	mul2 = p1;
	mul2 *= p2;

	cout << endl;

	cout << "Press any key to quit" << endl;
	cin.get();

}