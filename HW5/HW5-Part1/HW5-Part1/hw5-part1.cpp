#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//wipes the standard input stream clean
void refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

//find squares of integers <= N
void square(int N, int original, bool down)
{
	//find squares in descending order
	if (down)
	{
		//if number is still positive
		if (N > 0) 
		{
			//print the square if number is odd
			if (N % 2 == 1)
			{
				cout << N*N << ",";
			}
			//decrement N
			square(N - 1, original, true);
		}
		//reverse to find squares in ascending order
		else
		{
			//print the square if number is even
			if (N % 2 == 0 && N != 0)
			{
				cout << N*N << ",";
			}
			//increment N
			square(N + 1, original, false);
		}

	}
	//find squares in ascending order
	else
	{
		//if number does not exceed original input
		if (N <= original)
		{
			//print the square if number is even
			if (N % 2 == 0 && N != 0)
			{
				cout << N*N << ",";
			}
			//increment N
			square(N + 1, original, false);
		}
	}

}

int main()
{
	int num;

	do
	{
		cout << "Input a positive integer: ";
		cin >> num;
		if (cin.fail() || num < 0) //Error checking if input is not valid
		{
			cout << "\tPlease enter valid input" << endl;
		}
		refresh_cin();
	} while (num < 0); //Repeat if input was invalid

	square(num, num, true); //find squares of integers <= num

	cout << "\nPress ENTER to close" << endl;
	cin.get();
}