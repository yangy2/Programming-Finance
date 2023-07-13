//Yilin Yang
//Programming Finance HW6

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "booklist_yang.h"



int main()
{

	Booklist book;

	int choice;

	do
	{
		choice = book.print_menu();

		switch (choice)
		{
		case 1:
			cout << "Adding Entry to End of List" << endl;
			if (book.check(book.list) < 20)
			{
				int entry = book.getISBN();
				book.insert_at(book.list, entry, book.check(book.list));
				book.print_list(book.list);
			}
			else cout << "\tList is full!" << endl;
			break;

		case 2:
			cout << "Adding Entry to Position in List" << endl;
			if (book.check(book.list) < 20)
			{
				int position = book.getPosition();
				int entry = book.getISBN();
				book.insert_at(book.list, entry, position-1);
				book.print_list(book.list);
			}
			else cout << "\tList is full!" << endl;
			break;

		case 3:
			cout << "Locating Entry using Linear Search" << endl;
			if (book.check(book.list) > 0)
			{
				int entry = book.getISBN();
				int index = book.linear_search(book.list, entry);
				if (index != -1) cout << "\t" << entry << " found at position " << index + 1 << endl;
				else cout << "\tISBN not found in list..." << endl;
				book.print_list(book.list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 4:
			cout << "Locating Entry using Binary Search" << endl;
			if (book.check(book.list) > 0)
			{
				if (book.get_sort_status())
				{
					int entry = book.getISBN();
					int index = book.binary_search(book.list, 0, book.check(book.list), entry);
					if (index != -1) cout << "\t" << entry << " found at position " << index + 1 << endl;
					else cout << "\tISBN not found in list..." << endl;
					book.print_list(book.list);
				}
				else cout << "\tList is not sorted; cannot perform binary search" << endl;
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 5:
			cout << "Deleting Entry by List Position" << endl;
			if (book.check(book.list) > 0)
			{
				int position = book.getPosition();
				book.delete_at(book.list, 0, position);
				book.print_list(book.list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 6:
			cout << "Deleting Entry by ISBN Reference" << endl;
			if (book.check(book.list) > 0)
			{
				int entry = book.getISBN();
				book.delete_at(book.list, entry, 0);
				book.print_list(book.list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 7:
			cout << "Selection Sorting List" << endl;
			if (book.check(book.list) > 0)
			{
				book.selection_sort(book.list);
				book.print_list(book.list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 8:
			cout << "Bubble Sorting List" << endl;
			if (book.check(book.list) > 0)
			{
				book.bubble_sort(book.list);
				book.print_list(book.list);
			}
			else cout << "\tList is empty!" << endl;
			break;

		case 9:
			cout << "Printing List" << endl;
			if (book.check(book.list) > 0) book.print_list(book.list);
			else cout << "\tList is empty!" << endl;
			break;
		}

	} while (choice != 0);
}
