//Yilin Yang
//Inclass 2

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

int main()
{
	int x;

	do
	{
		cout << "Enter number of lines: ";
		cin >> x;
		if (cin.fail() || x < 0) //Error checking if input is not valid
		{
			cout << "\tPlease enter non-negative integer" << endl;
		}
		refresh_cin();
	} while (x < 0); //Repeat if input was invalid

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j <= i; j++) cout << "*";
		cout << endl;
	}

	system("Pause");
}