//Yilin Yang
//Programming Finance Final Project

#include <iostream>

#include "account_yilin_yang.h"
#include "bank_account_yilin_yang.h"
#include "stock_account_yilin_yang.h"

using std::cout;
using std::endl;
using std::cin;

//wipes the standard input stream clean
void refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

//print main menu and read user's selection
int main_menu()
{
	int choice;

	cout << "MENU" << endl;
	cout << "#####################################" << endl;
	cout << "# Choice 1: Stock Portfolio Account #" << endl;
	cout << "# Choice 2: Bank Account            #" << endl;
	cout << "# Choice 3: QUIT                    #" << endl;
	cout << "#####################################" << endl;

	do
	{
		cout << "Enter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 3) //Error checking if input is not valid
		{
			cout << "\tPlease enter a valid choice: 1-3" << endl;
		}
		refresh_cin();
	} while (choice < 1 || choice > 3); //Repeat if input was invalid

	return choice;
}

//print stock menu and read user's selection
int stock_menu()
{
	int choice;

	cout << "\tMENU - STOCK PORTFOLIO ACCOUNT" << endl;
	cout << "\t########################################" << endl;
	cout << "\t# Choice 1: Display Stock Symbol Price #" << endl;
	cout << "\t# Choice 2: Display Current Portfolio  #" << endl;
	cout << "\t# Choice 3: Buy Shares                 #" << endl;
	cout << "\t# Choice 4: Sell Shares                #" << endl;
	cout << "\t# Choice 5: View Portfolio Value Graph #" << endl;
	cout << "\t# Choice 6: View Transaction History   #" << endl;
	cout << "\t# Choice 7: RETURN TO PREVIOUS MENU    #" << endl;
	cout << "\t########################################" << endl;

	do
	{
		cout << "\tEnter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 7) //Error checking if input is not valid
		{
			cout << "\t\tPlease enter a valid choice: 1-7" << endl;
		}
		refresh_cin();
	} while (choice < 1 || choice > 7); //Repeat if input was invalid

	return choice;
}

//print bank menu and read user's selection
int bank_menu()
{
	int choice;

	cout << "\tMENU - BANK ACCOUNT" << endl;
	cout << "\t#####################################" << endl;
	cout << "\t# Choice 1: View Account Balance    #" << endl;
	cout << "\t# Choice 2: Deposit Money           #" << endl;
	cout << "\t# Choice 3: Withdraw Money          #" << endl;
	cout << "\t# Choice 4: Print History           #" << endl;
	cout << "\t# Choice 5: RETURN TO PREVIOUS MENU #" << endl;
	cout << "\t#####################################" << endl;

	do
	{
		cout << "\tEnter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 5) //Error checking if input is not valid
		{
			cout << "\t\tPlease enter a valid choice: 1-5" << endl;
		}
		refresh_cin();
	} while (choice < 1 || choice > 5); //Repeat if input was invalid

	return choice;
}

void main()
{
	int choice;

	Bank_Account bankAccount;
	Stock_Account stockAccount;

	do
	{
		choice = main_menu();

		switch (choice)
		{
		case 1:
			int choice_stock;

			do
			{
				choice_stock = stock_menu();

				switch (choice_stock)
				{
				case 1:
					cout << "\tDisplaying price for stock symbol..." << endl;
					stockAccount.display_stock();
					break;

				case 2:
					cout << "\tDisplaying current portfolio..." << endl;
					stockAccount.display_portfolio();
					break;

				case 3:
					cout << "\tBuying shares..." << endl;
					stockAccount.buy();
					break;

				case 4:
					cout << "\tSelling shares..." << endl;
					stockAccount.sell();
					break;

				case 5:
					cout << "\tDisplaying graph of portfolio value..." << endl;
					stockAccount.plot();
					break;

				case 6:
					cout << "\tDisplaying transaction history..." << endl;
					stockAccount.print_history();
					break;
				}
			} while (choice_stock != 7);

			break;

		case 2:
			int choice_bank;

			do
			{
				choice_bank = bank_menu();

				switch (choice_bank)
				{
				case 1:
					cout << "\tDisplaying account balance..." << endl;
					bankAccount.view_balance();
					break;

				case 2:
					cout << "\tDepositing money..." << endl;
					bankAccount.deposit();
					break;

				case 3:
					cout << "\tWithdrawing money..." << endl;
					bankAccount.withdraw();
					break;

				case 4:
					cout << "\tDisplaying history..." << endl;
					bankAccount.print_history();
					break;
				}
			} while (choice_bank != 5);

			break;
		}

	} while (choice != 3);
}