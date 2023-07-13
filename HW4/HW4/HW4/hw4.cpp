//Yilin Yang
//Programming Finance HW4

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int list[20] = { 0 };
bool sorted = false;

//wipes the standard input stream clean
void refresh_cin() 
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

//check how many entries are in an array
int check(int list[])
{
	int count = 0;

	for (int i = 0; i < 20; i++) 
	{ 
		if (list[i] != 0) count++;
	}

	return count;
}

//read user input for ISBN number
int getISBN()
{
	int ISBN;
	int min = 100000000;
	int max = 999999999;

	do
	{
		cout << "\tInput 9 digit ISBN number: ";
		cin >> ISBN;
		if (cin.fail() || ISBN < min || ISBN > max) //Error checking if input is not valid
		{
			cout << "\t\tPlease enter a valid 9 digit ISBN number" << endl;
		}
		refresh_cin();
	} while (ISBN < min || ISBN > max); //Repeat if input was invalid

	return ISBN;
}

//read user input for position in list
int getPosition()
{
	int position;
	int currentsize = check(list)+1;
	do
	{
		cout << "\tInput a position from the list: ";
		cin >> position;
		if (cin.fail() || position < 1 || position > currentsize) //Error checking if input is not valid
		{
			cout << "\t\tPosition mismatch with current list size" << endl;
		}
		refresh_cin();
	} while (position < 1 || position > currentsize); //Repeat if input was invalid

	return position;
}

//print contents of array
void print_list(int list[])
{
	for (int i = 0; i < 20; i++)
	{

		if (list[i] != 0)
		{
			cout << "\t";
			if (i < 9) cout << " "; //Print extra space if single digit i
			cout << i + 1 << ": ";
			cout << list[i] << endl; //Print element
		}
		else break;
	}
}

//insert new entry into array
void insert_at(int list[], int entry, int position)
{
	position--;
	if (list[position] != 0)
	{
		for (int i = 19; i > position; i--)
		{
			list[i] = list[i - 1];
		}
	}

	list[position] = entry;

	sorted = false;
}

//search for ISBN linearly
int linear_search(int list[], int entry)
{
	for (int i = 0; i < 20; i++)
	{
		if (list[i] == entry) return i; //return index if found
	}

	return -1; //return negative # if not found
}

//search for ISBN using binary search
int binary_search(int list[], int left, int right, int entry)
{

	if (right >= left)
	{
		int middle = (left + right) / 2;
//		cout << "Middle [" << middle << "] is " << list[middle] << endl;

		if (list[middle] == entry) return middle; //ISBN is found

		else if (list[middle] > entry)
		{
//			cout << "Checking left" << endl;
			return binary_search(list, left, middle - 1, entry); //search left half of list
		}

		else return binary_search(list, middle + 1, right, entry); //search right half of list
	}

	return -1; //ISBN not found
}

//delete an entry from array
void delete_at(int list[], int entry, int position)
{
	int index = 0; //index of array containing entry to delete

	if (entry) //deleting by finding ISBN number 
	{ 
		index = linear_search(list, entry);
		if (index == -1) cout << "\tISBN not found in list..." << endl;
		else list[index] = 0; 
	}

	else if (position) //deleting by finding position in array
	{	
		if (position > check(list)) //check if position entered is empty or not
		{
			cout << "\tThere was nothing at the position..." << endl;
			index = -1;
		}
		else //delete entry at position entered
		{
			index = position - 1;
			list[index] = 0;
		}
	}

	if(index != -1) //reorder elements based on space vacated by deletion
	{
		for (int i = index; i < 20; i++)
		{
			list[i] = list[i + 1];
		}
		cout << "\tDeleted element at position " << index + 1 << endl;
	}
}

//sort array using selection sort
void selection_sort(int list[])
{
	int limit = check(list);
	for (int i = 0; i < limit-1; i++)
	{
		int min = i;
//		cout << "Current min is " << *(list + min) << endl;

		for (int j = i+1; j < limit; j++)
		{
			if (*(list + j) < *(list + min))
			{
				min = j;
//				cout << "New min is " << *(list + min) << endl;
			}
		}

		if (min != 1)
		{
//			cout << "Swapping " << *(list + i) << " and " << *(list + min) << endl;
			int temp = *(list + i);
			*(list + i) = *(list + min);
			*(list + min) = temp;
		}
	}

	sorted = true;
}

//sort array using bubble sort
void bubble_sort(int list[])
{
	int limit = check(list);
	for (int i = 0; i < limit - 1; i++)
	{
		for (int j = 0; j < limit - 1 - i; j++)
		{
			//if element is larger than next one, swap them
			if (*(list + j) > *(list + j + 1))
			{
				int temp = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = temp;
			}
		}
	}

	sorted = true;
}

//print menu and read user's selection
int print_menu() 
{
	int choice;

	cout << "MENU" << endl;
	cout << "#####################################" << endl;
	cout << "# Choice 1: Add to end of list      #" << endl;
	cout << "# Choice 2: Add to position in list #" << endl;
	cout << "# Choice 3: Linearly search list    #" << endl;
	cout << "# Choice 4: Binary search list      #" << endl;
	cout << "# Choice 5: Delete by position      #" << endl;
	cout << "# Choice 6: Delete by name          #" << endl;
	cout << "# Choice 7: Selection sort list     #" << endl;
	cout << "# Choice 8: Bubble sort list        #" << endl;
	cout << "# Choice 9: View list               #" << endl;
	cout << "# Choice 0: QUIT                    #" << endl;
	cout << "#####################################" << endl;

	do
	{
		cout << "Enter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 0 || choice > 9) //Error checking if input is not valid
		{
			cout << "\tPlease enter a valid choice: 0-9" << endl;
		}
		refresh_cin();
	} while (choice < 0 || choice > 9); //Repeat if input was invalid

	return choice;
}

int main()
{
	int choice;

	do
	{
		choice = print_menu();

		switch (choice)
		{
		case 1:
			cout << "Adding Entry to End of List" << endl;
			if (check(list) < 20)
			{
				int entry = getISBN();
				insert_at(list, entry, check(list)+1);
				print_list(list);
			}
			else cout << "\tList is full!" << endl;
			break;

		case 2:
			cout << "Adding Entry to Position in List" << endl;
			if (check(list) < 20)
			{
				int position = getPosition();
				int entry = getISBN();
				insert_at(list, entry, position);
				print_list(list);
			}
			else cout << "\tList is full!" << endl;
			break;

		case 3:
			cout << "Locating Entry using Linear Search" << endl;
			if (check(list) > 0)
			{
				int entry = getISBN();
				int index = linear_search(list, entry);
				if (index != -1) cout << "\t" << entry << " found at position " << index + 1 << endl;
				else cout << "\tISBN not found in list..." << endl;
				print_list(list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 4:
			cout << "Locating Entry using Binary Search" << endl;
			if (check(list) > 0)
			{
				if (sorted)
				{
					int entry = getISBN();
					int index = binary_search(list, 0, check(list), entry);
					if (index != -1) cout << "\t" << entry << " found at position " << index + 1 << endl;
					else cout << "\tISBN not found in list..." << endl;
					print_list(list);
				}
				else cout << "\tList is not sorted; cannot perform binary search" << endl;
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 5:
			cout << "Deleting Entry by List Position" << endl;
			if (check(list) > 0)
			{
				int position = getPosition();
				delete_at(list, 0, position);
				print_list(list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 6:
			cout << "Deleting Entry by ISBN Reference" << endl;
			if (check(list) > 0)
			{
				int entry = getISBN();
				delete_at(list, entry, 0);
				print_list(list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 7:
			cout << "Selection Sorting List" << endl;
			if (check(list) > 0)
			{
				selection_sort(list);
				print_list(list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 8:
			cout << "Bubble Sorting List" << endl;
			if (check(list) > 0)
			{
				bubble_sort(list);
				print_list(list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 9:
			cout << "Printing List" << endl;
			if(check(list) > 0) print_list(list);
			else cout << "\tList is empty!" << endl;
			break;
		}

	} while (choice != 0);
}