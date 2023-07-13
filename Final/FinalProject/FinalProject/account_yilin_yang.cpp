//Yilin Yang
//Programming Finance Final Project

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "account_yilin_yang.h"

using namespace std;

//wipes the standard input stream clean
void Account::refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

double Account::get_balance()
{
	ifstream fileIn("balance.txt");

	if (fileIn.is_open()) fileIn >> balance;
	else cout << "Error accessing external file" << endl;

	return balance;
}

void Account::set_balance(double value)
{
	ofstream fileOut("balance.txt");
	if (fileOut.is_open()) fileOut << value;
	else cout << "Error accessing external file" << endl;
}

void Account::write_history(string event, double amount)
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
	string str(buffer);

	//Store transaction history
	ofstream fileOut("bank_transaction_history.txt", ofstream::app);
	if (fileOut.is_open())
	{
		fileOut << left << setw(25) << event;
		fileOut << left << setw(20) << amount;
		fileOut << left << setw(30) << str;
		fileOut << left << setw(15) << get_balance() << endl;
		fileOut.close();
	}
}

void Account::print_history()
{
	string line;
	ifstream fileIn("bank_transaction_history.txt");
	cout << left << setw(25) << " Event ";
	cout << left << setw(20) << "Amount $";
	cout << left << setw(30) << "Date & Time";
	cout << left << setw(15) << "Balance $" << endl;

	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			getline(fileIn, line);
			cout << line << endl;
		}
	}
	else cout << "Error accessing external file" << endl;
}