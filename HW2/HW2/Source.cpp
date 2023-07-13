//Yilin Yang
//Programming Finance HW2
#include <iostream>
#include <conio.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int iterations; //number of times to run algorithm
	long incircle = 0; //number of points in shaded area
	double x, y, pi; //(x,y) coordinates and estimate pi 

	do //Obtain number of iterations from user
	{
		cout << "Input iterations to perform Monte Carlo Algorithm" << endl;
		cin >> iterations;
		if (cin.fail() || iterations < 1) //Error checking if input not positive number
		{
			cout << "Input must be a positive integer" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		}
	} while (iterations < 1);

	std::ofstream file; //setup external file
	file.open("coordinates.txt");

	//Generate random coordinates
	for (long i = 0; i < iterations; i++)
	{
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;

		if (i < 100) file << x << "\t" << y << "\n"; //write coordinates to file

		if (x*x + y*y <= 1) incircle++;

		pi = 4 * ((double(incircle)) / (double(iterations)));
		if (pi == 3.14) break; //stop early if pi has been correctly estimated
	}

	cout << "Monte Carlo Algorithm estimated pi value of " << pi << " across " << iterations << " iterations." << endl;
	_getch();
	return 0;
}