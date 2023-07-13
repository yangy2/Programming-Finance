// Yilin Yang
// Programming Finance HW 8

#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "sphere.h"
#include "tetrahedron.h"

using std::cout;
using std::endl;
using std::cin;

//wipes the standard input stream clean
void refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

//print menu and read user's selection
int print_menu()
{
	int choice;

	cout << "MENU" << endl;
	cout << "##################################" << endl;
	cout << "# Choice 1: Circle               #" << endl;
	cout << "# Choice 2: Equilateral Triangle #" << endl;
	cout << "# Choice 3: Sphere               #" << endl;
	cout << "# Choice 4: Regular Tetrahedron  #" << endl;
	cout << "# Choice 0: QUIT                 #" << endl;
	cout << "##################################" << endl;

	do
	{
		cout << "Enter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 0 || choice > 4) //Error checking if input is not valid
		{
			cout << "\tPlease enter a valid choice: 0-4" << endl;
		}
		refresh_cin();
	} while (choice < 0 || choice > 4); //Repeat if input was invalid

	return choice;
}

int main()
{
	int choice;

	circle cir;
	triangle tri;
	sphere sph;
	tetrahedron tet;

	do
	{
		choice = print_menu();

		int x = 0, y = 0, z = 0;
		double radius = 0, length = 0;
		bool flag = true; // flag check if user input is valid

		switch (choice)
		{
		case 1:
			cout << "You chose Circle" << endl;
			do
			{
				cout << "\tEnter the center point as (x, y) coordinates: ";
				cin >> x >> y;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag) //Error checking if input is not valid
				{
					cout << "\t\tCoordinates must be integers" << endl;
				}
				refresh_cin();
			} while (!flag); //Repeat if input was invalid
			
			cir.set_x(x);
			cir.set_y(y);

			do
			{
				cout << "\tEnter the radius: ";
				cin >> radius;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag || radius <= 0) //Error checking if input is not valid
				{
					cout << "\t\tRadius must be positive" << endl;
				}
				refresh_cin();
			} while (!flag || radius <= 0); //Repeat if input was invalid

			cir.set_radius(radius);

			cout << "For a circle of radius " << cir.get_radius(); 
			cout << " located at (" << cir.get_x() << ", " << cir.get_y() << ")" << endl;
			
			cir.print();

			break;

		case 2:
			cout << "You chose Equilateral Triangle" << endl;
			do
			{
				cout << "\tEnter the center point as (x, y) coordinates: ";
				cin >> x >> y;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag) //Error checking if input is not valid
				{
					cout << "\t\tCoordinates must be integers" << endl;
				}
				refresh_cin();
			} while (!flag); //Repeat if input was invalid

			tri.set_x(x);
			tri.set_y(y);

			do
			{
				cout << "\tEnter the side length: ";
				cin >> length;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag || length <= 0) //Error checking if input is not valid
				{
					cout << "\t\tLength must be positive" << endl;
				}
				refresh_cin();
			} while (!flag || length <= 0); //Repeat if input was invalid

			tri.set_length(length);

			cout << "For a triangle with side length " << tri.get_length();
			cout << " located at (" << tri.get_x() << ", " << tri.get_y() << ")" << endl;

			tri.print();

			break;

		case 3:
			cout << "You chose Sphere" << endl;
			do
			{
				cout << "\tEnter the center point as (x, y, z) coordinates: ";
				cin >> x >> y >> z;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag) //Error checking if input is not valid
				{
					cout << "\t\tCoordinates must be integers" << endl;
				}
				refresh_cin();
			} while (!flag); //Repeat if input was invalid

			sph.set_x(x);
			sph.set_y(y);
			sph.set_z(z);

			do
			{
				cout << "\tEnter the radius: ";
				cin >> radius;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag || radius <= 0) //Error checking if input is not valid
				{
					cout << "\t\tRadius must be positive" << endl;
				}
				refresh_cin();
			} while (!flag || radius <= 0); //Repeat if input was invalid

			sph.set_radius(radius);

			cout << "For a sphere with radius " << sph.get_radius();
			cout << " located at (" << sph.get_x() << ", " << sph.get_y() << ", " << sph.get_z() << ")" << endl;

			sph.print();

			break;

		case 4:
			cout << "You chose Regular Tetrahedron" << endl;
			do
			{
				cout << "\tEnter the center point as (x, y, z) coordinates: ";
				cin >> x >> y >> z;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag) //Error checking if input is not valid
				{
					cout << "\t\tCoordinates must be integers" << endl;
				}
				refresh_cin();
			} while (!flag); //Repeat if input was invalid

			tet.set_x(x);
			tet.set_y(y);
			tet.set_z(z);

			do
			{
				cout << "\tEnter the side length: ";
				cin >> length;
				if (cin.fail()) flag = false;
				else flag = true;
				if (!flag || length <= 0) //Error checking if input is not valid
				{
					cout << "\t\tLength must be positive" << endl;
				}
				refresh_cin();
			} while (!flag || length <= 0); //Repeat if input was invalid

			tet.set_length(length);

			cout << "For a tetrahedron with side length " << tet.get_length();
			cout << " located at (" << tet.get_x() << ", " << tet.get_y() << ", " << tet.get_z() << ")" << endl;

			tet.print();

			break;
		}

	} while (choice != 0);

}