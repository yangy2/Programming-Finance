//Yilin Yang
//Programming Finance Final Project

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "account_yilin_yang.h"
#include "bank_account_yilin_yang.h"

using namespace std;

void Bank_Account::view_balance()
{
	cout << "\tYou have $" << get_balance() << " in your bank account" << endl;
}

void Bank_Account::deposit()
{
	do
	{
		cout << "\tEnter Amount to Deposit: ";
		cin >> depositAmount;
		if (cin.fail() || depositAmount < 0) //Error checking if input is not valid
		{
			cout << "\t\tPlease enter a positive amount" << endl;
		}
		refresh_cin();
	} while (depositAmount < 0); //Repeat if input was invalid

	set_balance(get_balance() + depositAmount);
	cout << "\t$" << depositAmount << " was deposited to your account" << endl;

	write_history("Deposit", depositAmount);
}

void Bank_Account::withdraw()
{
	if (get_balance() > 0)
	{
		do
		{
			cout << "\tEnter Amount to Withdraw: ";
			cin >> withdrawAmount;
			if (cin.fail() || withdrawAmount < 0 || get_balance() < withdrawAmount) //Error checking if input is not valid
			{
				cout << "\t\tPlease enter a positive amount" << endl;
				cout << "\t\tAmount cannot exceed current balance: $" << get_balance() << endl;
			}
			refresh_cin();
		} while (withdrawAmount < 0 || get_balance() < withdrawAmount); //Repeat if input was invalid

		set_balance(get_balance() - withdrawAmount);
		cout << "\t$" << withdrawAmount << " was withdrawn from your account" << endl;

		write_history("Withdraw", withdrawAmount);
	}

	else cout << "\tBalance is empty! Cannot withdraw" << endl;
}