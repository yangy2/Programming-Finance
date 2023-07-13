//Yilin Yang
//Programming Finance HW10

#include <iostream>
#include <string>

#include "node_yilin_yang.h"
#include "linked_list_yilin_yang.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

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
	cout << "#######################################" << endl;
	cout << "# Choice 1: Add node to front of list #" << endl;
	cout << "# Choice 2: Add node to end of list   #" << endl;
	cout << "# Choice 3: Remove front node         #" << endl;
	cout << "# Choice 4: Remove end node           #" << endl;
	cout << "# Choice 5: Remove node by number     #" << endl;
	cout << "# Choice 6: Remove node by name       #" << endl;
	cout << "# Choice 7: Print list                #" << endl;
	cout << "# Choice 8: QUIT                      #" << endl;
	cout << "#######################################" << endl;

	do
	{
		cout << "Enter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 8) //Error checking if input is not valid
		{
			cout << "\tPlease enter a valid choice: 1-8" << endl;
		}
		refresh_cin();
	} while (choice < 1 || choice > 8); //Repeat if input was invalid

	return choice;
}

int main()
{
	int choice;

	Node *node;
	LinkedList list;

	do
	{
		choice = print_menu();

		int number = 0;
		string name;

		switch (choice)
		{
		case 1:
			cout << "Adding New Node to Beginning of List" << endl;
			do
			{
				cout << "\tEnter Item Number: ";
				cin >> number;
				if (cin.fail() || number < 1) //Error checking if input is not valid
				{
					cout << "\t\tInput should be a positive integer" << endl;
				}
				refresh_cin();
			} while (number < 1); //Repeat if input was invalid

			cout << "\tEnter Item Name: ";
			cin >> name;

			node = new Node(name, number);
			list.addToStart(node);
			list.printList();
			break;

		case 2:
			cout << "Adding New Node to End of List" << endl;
			do
			{
				cout << "\tEnter Item Number: ";
				cin >> number;
				if (cin.fail() || number < 1) //Error checking if input is not valid
				{
					cout << "\t\tInput should be a positive integer" << endl;
				}
				refresh_cin();
			} while (number < 1); //Repeat if input was invalid

			cout << "\tEnter Item Name: ";
			cin >> name;

			node = new Node(name, number);
			list.addToEnd(node);
			list.printList();
			break;

		case 3:
			cout << "Removing Node at Beginning of List" << endl;
			if (!list.removeFromStart()) cout << "\tList is already empty!" << endl;
			else list.printList();
			break;

		case 4:
			cout << "Removing Node at End of List" << endl;
			if (!list.removeFromEnd()) cout << "\tList is already empty!" << endl;
			else list.printList();
			break;

		case 5:
			cout << "Removing Node from List by Item Number" << endl;
			do
			{
				cout << "\tEnter Item Number: ";
				cin >> number;
				if (cin.fail() || number < 1) //Error checking if input is not valid
				{
					cout << "\t\tInput should be a positive integer" << endl;
				}
				refresh_cin();
			} while (number < 1); //Repeat if input was invalid

			list.removeNodeFromList(number);
			if (list.size() == 0) cout << "\tList is empty..." << endl;
			else list.printList();			
			break;

		case 6:
			cout << "Removing Node from List by Item Name" << endl;
			cout << "\tEnter Item Name: ";
			cin >> name;

			list.removeNodeFromList(name);
			if (list.size() == 0) cout << "\tList is empty..." << endl;
			else list.printList();
			break;

		case 7:
			cout << "Printing List" << endl;
			if (list.size() == 0) cout << "\tList is empty..." << endl;
			else list.printList();
			break;

		}

	} while (choice != 8);
}