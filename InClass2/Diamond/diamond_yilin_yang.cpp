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
		if (cin.fail() || x % 2 != 1) //Error checking if input is not valid
		{
			cout << "\tPlease enter positive odd integer" << endl;
		}
		refresh_cin();
	} while (x % 2 != 1); //Repeat if input was invalid

	int spaces = x / 2 + 1;

	for (int i = 1; i <= spaces; i++)
	{
		for (int j = 0; j < spaces - i; j++) cout << " ";

		for (int j = 0; j < 2 * i - 1; j++)	cout << "*";

		cout << endl;
	}

	for (int i = spaces - 1; i > 0; i--)
	{
		for (int j = 0; j < spaces - i; j++) cout << " ";
		
		for (int j = 0; j < 2 * i - 1; j++) cout << "*";

		cout << endl;
	}

	system("Pause");
}