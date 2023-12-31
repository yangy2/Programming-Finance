// SetTest.cpp
// Driver program for class IntegerSet.

#include <iostream>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main()
{
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nSet A is : \n";
	a.printSet();

	cout << "\nEnter set B:\n";
	b.inputSet();
	cout << "\nSet B is : \n";
	b.printSet();

	/* Write call to unionOfSets for object a, passing b as argument and assigning the result to c */
	c = a.UnionOfSet(b);
	cout << "\nUnion of A and B is:\n";
	c.printSet();

	/* Write call to intersectionOfSets for object a, passing b as argument and assigning the result to d */
	d = a.IntersectionOfSet(b);
	cout << "\nIntersection of A and B is:\n";
	d.printSet();

	a.refresh_cin();
	cout << "Press any key to end" << endl;
	cin.get();

	return 0;
}
