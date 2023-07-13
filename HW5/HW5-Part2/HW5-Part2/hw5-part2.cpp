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

//print out state of puzzle
void print_state(int list[], int index, int size)
{

	cout << "\t[";
	for (int i = 0; i < size; i++)
	{
		cout << " ";
		if (i == index) cout << "<";
		cout << list[i];
		if (i == index) cout << ">";
		cout << " ";
	}
	cout << "]" << endl;
}

//search for puzzle solution
bool jump(int list[], int mem[], int index, int size)
{
	//check that starting index is inbounds
	if (index < size && index > -1)
	{
		cout << "Index: " << index << endl;
		print_state(list, index, size);

		//check if current element is zero
		//if so, puzzle is solved
		if (list[index] == 0) return true;

		//check if current element already visited
		if (mem[index] == -1) //we've been here before, last move made no progress
		{
			cout << "\tReturned to Index: " << index << endl;
			cout << "\tNo Viable Moves to Right" << endl;
			return false;
		}

		else mem[index] = -1; //we haven't been here before, mark as visited now

		//otherwise, begin solving
		int currentval = list[index];

		//try moving right
		int newdex = index + currentval;
		cout << "\tMove Right to Index: " << newdex << endl;
		if(jump(list, mem, newdex, size)) return true;

		//try moving left
		else
		{
			cout << "Index: " << index << endl;
			print_state(list, index, size);
			newdex = index - currentval;
			cout << "\tReturned to Index: " << index << endl;
			cout << "\tMove Left to Index: " << newdex << endl;

			jump(list, mem, newdex, size);

		}
	}

	else 
	{ 
		cout << "\t\tOut of Bounds" << endl;
		return false;
	}
}

int main()
{
//	int list[] = { 3,2,3,1,6,2,5,1,0 };
//	int list[] = { 3,2,1,3,0 };
//	const int size = sizeof(list) / sizeof(int);

	const int max = 50;

	int list[max];
	int mem[max] = { 0 }; //Record if index has been visited before (write -1)

	int size;

	do
	{
		cout << "How many elements in puzzle? (Maximum supported is " << max << ")" << endl;
		cin >> size;
		if (cin.fail() || size < 2 || size > max) //Error checking if input is not valid
		{
			cout << "\tPlease input positive integer between 2 and " << max << endl;
			refresh_cin();
		}
	} while (size < 2 || size > max); //Repeat if input was invalid


	for (int i = 0; i < size-1; i++)
	{
		do
		{
			cout << "Input element at index " << i << "?" << endl;
			cin >> list[i];
			if (cin.fail() || list[i] < 1) //Error checking if input is not valid
			{
				cout << "\tPlease input positive integer" << endl;
				refresh_cin();
			}
		} while (list[i] < 1); //Repeat if input was invalid
	}
	cout << "Element at index " << size - 1 << " set to zero" << endl;
	list[size-1] = 0;

	bool solvable = jump(list, mem, 0, size);

	if (solvable) cout << "Puzzle solvable" << endl;
	else cout << "Puzzle not solvable" << endl;
	refresh_cin();

	cout << "Press ENTER key to close" << endl;
	cin.get();
}