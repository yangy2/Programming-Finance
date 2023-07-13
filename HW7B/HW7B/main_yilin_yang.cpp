//Yilin Yang
//Programming Finance HW7

#include<iostream>
#include"polynomial_yilin_yang.h"

using std::cout;
using std::endl;
using std::cin;

void main()
{
	polynomial p1, p2, add, sub, mul;

	cout << "Enter the First Polynomial" << endl;
	p1.getdata();

	cout << endl;

	cout << "Enter the Second Polynomial" << endl;
	p2.getdata();

	cout << endl;

	cout << "The First Polynomial is: " << p1 << endl;
	cout << "The Second Polynomial is: " << p2 << endl;

	cout << endl;

	cout << "Adding polynomial yields: " << (p1 + p2) << endl;
	add = p1;
	cout << "+= the polynomial yields: " << (add += p2) <<endl;

	cout << endl;

	cout << "Subtracting the polynomial yields: " << (p1 - p2) << endl;
	sub = p1;
	cout << "-= the polynomial yields: " << (sub -= p2) << endl;

	cout << endl; 

	cout << "Multiplying the polynomial yields: " << (p1 * p2) << endl;
	mul = p1;
	cout << "*= the polynomial yields: " << (mul *= p2) << endl;

	cout << endl;

	cout << "Press ENTER to quit" << endl;
	cin.get();
}