// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;

/* Write include directive for IntegerSet.h here */
#include "Integerset.h"

//wipes the standard input stream clean
void IntegerSet::refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet()
{
	int number;

	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (!cin.fail()) // check if input is a number
		{
			if (validEntry(number))
				set[number] = 1;
			else if (number != -1)
				cout << "Invalid Element\n";
		}
		else
		{
			cout << "Not a number" << endl;
			refresh_cin();
		}
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";

	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";

	cout << "}" << endl;
} // end function printSet

	  /* Write definition for unionOfSets */
IntegerSet IntegerSet::UnionOfSet(IntegerSet set2)
{
	IntegerSet set3;

	for (int i = 0; i < 101; i++)
	{
		if (set[i] == 1 || set2.set[i] == 1) set3.set[i] = 1;
	}
	return set3;
}

	  /* Write definition for intersectionOfSets */
IntegerSet IntegerSet::IntersectionOfSet(IntegerSet set2)
{
	IntegerSet set3;

	for (int i = 0; i < 101; i++)
	{
		if (set[i] == 1 && set2.set[i] == 1) set3.set[i] = 1;
	}
	return set3;
}
