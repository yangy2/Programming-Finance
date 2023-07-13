//Yilin Yang
//Programming Finance Final Project

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <time.h>
#include <sstream>
#include <iomanip>

#include "account_yilin_yang.h"
#include "stock_account_yilin_yang.h"
#include "node_yilin_yang.h"

#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib" )    
#pragma comment( lib, "libeng.lib" )

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif

#include "mex.h"
#include <engine.h>

using namespace std;

/* Functions for Stock Actions */
//constructor to read data from external files into data struct
Stock_Account::Stock_Account()
{
	num1 = num2 = size = 0;

	string line, symbol;
	stringstream stream;

	double price;

	ifstream file1("Result1.txt");
	ifstream file2("Result2.txt");

	if (file1.is_open() && file2.is_open())
	{
		while (!file1.eof() && !file2.eof())
		{
			getline(file1, line);
			stream << line;
			stream >> symbol >> price;
			result1.insert(pair<string, double>(symbol, price));
			stream.str(" ");
			stream.clear();

			getline(file2, line);
			stream << line;
			stream >> symbol >> price;
			result2.insert(pair<string, double>(symbol, price));
			stream.str(" ");
			stream.clear();
		}
	}

	file1.close();
	file2.close();

	this->read_portfolio();
	this->read_value();
}

//randomly choose file to read from
sym Stock_Account::get_File(sym result1, sym result2)
{
	srand(time(NULL));
	if (rand() % 2 == 0) return result1;
	else return result2;
}

//show stocks for company input
void Stock_Account::display_stock()
{
	bool found = false;
	string symbol;

	cout << "\tEnter stock symbol: ";
	cin >> symbol;

	sym::iterator iter;
	sym file = get_File(result1, result2);

	for (iter = file.begin(); iter != file.end(); iter++)
	{
		if (symbol == iter->first)
		{
			cout << "\t\tCompany Symbol \tPricePerShare" << endl;
			cout << "\t\t" << iter->first << "\t\t" << iter->second << endl;
			found = true;
		}
	}

	if (!found) cout << "\t\tCould not find Company Symbol: " << symbol << endl;
}

//update list after buying share
void Stock_Account::buy_update(string sym, int pri)
{
	Node *temp;
	temp = new Node(sym, pri);

	Node *found = search(sym);

	if (found == NULL)
	{
		if (tail == NULL&&head == NULL)
		{
			temp->previous = NULL;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else //add to end of list
		{
			Node *copy = tail;
			tail->next = temp;
			tail = temp;
			tail->previous = copy;

		}
		size++;
	}
	else found->price = temp->price + found->price;
	sort();
}

//update list after selling share
void Stock_Account::sell_update(Node *node, int n)
{
	node->price = node->price - n;

	if (node->price == 0)
	{
		if (node == head)
		{
			if (node == tail)
			{
				head = tail = NULL;
				delete node;
				size--;
				return;
			}
			Node *temp1 = node->next;
			head = node->next;
			temp1->previous = NULL;
			delete node;
			size--;
			return;
		}
		else if (node == tail)
		{
			if (node == head)
			{
				head = tail = NULL;
				delete node;
				size--;
				return;
			}
			Node *temp2 = node->previous;
			tail = node->previous;
			temp2->next - NULL;
			delete node;
			size--;
			return;
		}
		else
		{
			Node *temp3 = node->previous;
			Node *temp4 = node->next;
			temp3->next = node->next;
			temp4->previous = node->previous;
			delete node;
			size--;
			return;
		}
	}
}

void Stock_Account::buy()
{
	bool found = false;
	string symbol;
	double price;
	sym copy = get_File(result1, result2);

	cout << "\tEnter stock symbol: ";
	cin >> symbol;

	
	for (sym::iterator iter = copy.begin(); iter != copy.end(); iter++)
	{
		if (symbol == iter->first)
		{
			found = true;
			price = iter->second;
		}
	}
	if (!found)
	{
		cout << "\tSymbol not found" << endl;
		return;
	}

	int stocks;
	double maximum;
	double cost;

	cout << "\tEnter the number of Stocks you want to buy : ";
	cin >> stocks;
	cout << "\tEnter the Maximum Amount willing to pay per stock : ";
	cin >> maximum;

	//Check if Stock price is less than max amount
	if (maximum > price)
	{
		cost = stocks * price;
	}
	else
	{
		cout << "\nTransaction Incomplete! Stock price is too high, cant buy stock at this price\n";
		return;
	}

	//check if sufficient funds are available
	if (cost <= get_balance())
	{
		set_balance(get_balance() - cost);
		cout << "\nTransaction Complete! You have purchased " << stocks << " shares of " << symbol << " for amount $" << cost << endl;

		//record stock transaction
		write_history("Buy", symbol, stocks, price, cost);

		//record bank transaction
		Account::write_history("Withdraw (Purchase)", cost);
	}
	else
	{
		cout << "Invalid Transaction! Insufficient Balance\n";
		return;
	}

	//update the list
	buy_update(symbol, stocks);
	sort();
	write_value();
	write_portfolio();
}

void Stock_Account::sell()
{
	bool found = false;
	string symbol;
	double price;	
	Node *temp = NULL;

	cout << "\tEnter stock symbol: ";
	cin >> symbol;
	temp = search(symbol);

	if (temp != NULL)
	{
		found = true;
	}

	if (!found)
	{
		cout << "\tSymbol not found!" << endl;
		return;
	}

	int stocks;
	double minimum;
	double cost;

	cout << "\tEnter the number of shares you want to sell: ";
	cin >> stocks;

	if (stocks > temp->price)
	{
		cout << "\tNumber of shares is out of range" << endl;
		return;
	}

	cout << "\tEnter minimum amount you want to sell per share: ";
	cin >> minimum;

	sym sym_temp = get_File(result1, result2);
	
	for (sym::iterator iter = sym_temp.begin(); iter != sym_temp.end(); iter++)
	{
		if (symbol == iter->first)
		{
			price = iter->second;
		}
	}

	if (price < minimum)
	{
		cout << "\tSell price is high, Transaction Incomplete!\n";
		return;
	}

	//Get recent cash balance
	cost = stocks * price;
	set_balance(get_balance() + cost);
	cout << "\tTransaction Complete! You have sold " << stocks << " shares of " << symbol << " for amount $" << cost << endl;

	//record stock transaction
	write_history("Sell", symbol, stocks, price, cost);

	//record bank transaction
	Account::write_history("Deposit (Sale)", cost);

	sell_update(temp, stocks);
	sort();
	write_value();
	write_portfolio();
}

/* Supporting Functions for Stock Actions */
//sort list
void Stock_Account::sort()
{
	double x = 0;
	double y = 0;;

	if (head != NULL)
	{
		bool flag = false;
		Node *current = head;
		Node *prev = 0;
		Node *temp = NULL;
		sym temp_sym;

		for (int i = 0; i < size; i++)
		{
			while (current->next != 0)
			{
				temp_sym = get_File(result1, result2);
				temp = current->next;

				for (sym::iterator iter = temp_sym.begin(); iter != temp_sym.end(); iter++)
				{
					if (current->symbol == iter->first) x = iter->second;
					
					if (temp->symbol == iter->first) y = iter->second;
				}

				//comparing stock value
				if ((current->price)*x < (temp->price)*y)
				{
					temp->previous = current->previous;
					current->previous = temp;
					current->next = temp->next;

					flag = true;

					if (current->next != NULL) current->next->previous = current;
					temp->next = current;

					if (prev != 0) prev->next = temp;
					prev = temp;

					if (head == current) head = temp;

					if (current->next == 0) tail = current;
				}

				else
				{
					prev = current;
					current = current->next;
				}
			}

			if (!flag) break;

			else
			{
				prev = NULL;
				current = head;
				flag = false;
			}
		}
	}
}

//check if stock exists in portfolio
Node * Stock_Account::search(string sym)
{
	Node *current = head;

	while (current != NULL)
	{
		if (current->symbol == sym) return current;
		current = current->next;
	}

	//Return NULL if symbol not found
	return NULL; 
}

//check if list empty or not
bool Stock_Account::isEmpty() const
{
	return(head == 0 && tail == 0);

}

/* Functions for Portfolio Actions */
void Stock_Account::display_portfolio()
{
	sort();

	Node *current = head;
	sym copy = get_File(result1, result2);

	double pr, val, port_val;
	double stock_val = 0;

	if (size > 0)
	{
		cout << endl << left << setw(20) << "Symbol";
		cout << left << setw(20) << "Shares";
		cout << left << setw(20) << "PricePerShare($)";
		cout << left << setw(20) << "Total Value($)" << endl;
	}
	while (current != NULL)
	{
		for (sym::iterator iter = copy.begin(); iter != copy.end(); iter++)
		{
			if (current->symbol == iter->first)
			{
				pr = iter->second;
				val = current->price*pr;

				cout << left << setw(20) << current->symbol;
				cout << left << setw(20) << current->price;
				cout << left << setw(20) << pr;
				cout << left << setw(20) << val << endl;
				stock_val = stock_val + val;
			}
		}
		current = current->next;
	}

	if (size > 0)
	{
		cout << "Cash: $" << get_balance() << endl;
		cout << "Stock: $" << stock_val << endl;
		port_val = get_balance() + stock_val;
		cout << "Total Portfolio value: $" << port_val << endl;
	}
	else if (size == 0)
	{
		port_val = get_balance();
		cout << "Total portfolio value: $" << port_val << endl;
		cout << "You don't have any shares currently" << endl;
	}

}

void Stock_Account::read_portfolio()
{
	bool flag = false;

	string line, symbol;
	stringstream stream;
	int share;

	sym temp;

	ifstream fileIn("portfolio.txt");
	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			getline(fileIn, line);
			stream << line;
			stream >> symbol >> share;
			temp.insert(pair<string, int>(symbol, share));
			stream.clear();
			flag = true;
		}
	}
	fileIn.close();

	if (flag)
	{
		for (sym::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			buy_update(iter->first, iter->second);
		}
	}
}

void Stock_Account::read_value()
{
	string line, temp;
	stringstream stream;

	ifstream fileIn("portfolio.txt");
	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			getline(fileIn, line);
			stream << line;
			stream >> port_array[num1] >> time_array[num2] >> temp;

			if (time_array[num2] == "") continue;
			else
			{
				time_array[num1].append(" ");
				time_array[num1].append(temp);
			}
			num1++;
			num2++;
			stream.clear();
		}
	}
	fileIn.close();
}

void Stock_Account::write_portfolio()
{
	sort();
	Node *temp = head;
	ofstream fileOut("portfolio.txt");
	if (fileOut.is_open())
	{
		while (temp != NULL)
		{
			fileOut << temp->symbol << "\t" << temp->price << endl;
			temp = temp->next;
		}
	}
	fileOut.close();
}

void Stock_Account::write_value()
{
	Node *ptr = head;
	double cost = 0;
	double total = 0;
	double port_val = 0;

	sym copy = get_File(result1, result2);;

	while (ptr != NULL)
	{
		for (sym::iterator iter = copy.begin(); iter != copy.end(); iter++)
		{
			if (ptr->symbol == iter->first)
			{
				cost = iter->second;
				total = total + ptr->price*cost;
			}
		}

		ptr = ptr->next;
	}

	port_val = total + get_balance();

	if (num1 < 100) port_array[num1] = port_val;

	//generating the current date and time 
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
	std::string str(buffer);

	if (num2 < 100) time_array[num2] = str;

	if (size == 0) port_val = get_balance();

	ofstream fileOut("pvalue.txt", ios::app);
	if (fileOut.is_open())
	{
		fileOut << port_val << "  " << str << endl;
		fileOut.close();
	}
	num1++;
	num2++;
}

/* Functions for History */
void Stock_Account::write_history(string event, string symbol, int stocks, double price, double cost)
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
	string str(buffer);

	//Store transaction history
	ofstream stockOut("stock_transaction_history.txt", ofstream::app);
	if (stockOut.is_open())
	{
		stockOut << left << setw(10) << event;
		stockOut << left << setw(15) << symbol;
		stockOut << left << setw(15) << stocks;
		stockOut << left << setw(20) << price;
		stockOut << left << setw(20) << cost;
		stockOut << left << setw(25) << str << endl;
		stockOut.close();
	}
}

void Stock_Account::print_history()
{
	string line;
	ifstream fileIn("stock_transaction_history.txt");
	cout << left << setw(10) << "Event";
	cout << left << setw(15) << "Company";
	cout << left << setw(15) << "Shares";
	cout << left << setw(20) << "PricePerShare";
	cout << left << setw(20) << "Value($)";
	cout << left << setw(25) << "Date & Time" << endl;

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

//Plot graph using MATLAB
void Stock_Account::plot()
{

	cout << "Potfolio Value" << "\t\t" << "Date & Time" << endl;
	for (int i = 0; i < num1; i++)
	{
		cout << "$" << port_array[i] << "\t\t" << time_array[i] << endl;
	}

	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found." << endl;
		exit(1);
	}

	// create mxArray and copy arrays into it
	mxArray *A;
	A = mxCreateDoubleMatrix(1, num1, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)port_array, num1 * sizeof(double));
	engPutVariable(ep, "yy", A);

	// plotting function.
	engEvalString(ep, "plot(yy);");

	//  title for graph
	engEvalString(ep, "title('Portfolio Value Variation graph');");

	mxDestroyArray(A); // destroy mxArray 

}