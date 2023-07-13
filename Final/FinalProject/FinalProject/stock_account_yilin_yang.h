//Yilin Yang
//Programming Finance Final Project

#pragma once
#ifndef STOCK_ACCOUNT_YILIN_YANG_H
#define STOCK_ACCOUNT_YILIN_YANG_H

#include <string>
#include <map>
#include "account_yilin_yang.h"
#include "node_yilin_yang.h"

using std::string;
using std::map;

typedef map<string, double>sym;

class Stock_Account : public Account
{
public:

	Stock_Account();

	sym get_File(sym, sym);
	void display_stock();
	void buy_update(string, int);
	void sell_update(Node*, int);
	void buy();
	void sell();

	Node *search(string);
	bool isEmpty() const;
	void sort();
	virtual void write_history(string, string, int, double, double);
	virtual void print_history();

	void read_portfolio();
	void read_value();
	void write_portfolio();
	void write_value();
	void display_portfolio();
	void plot();

private:
	Node *head;
	Node *tail;

	int num1, num2, size;
	sym result1, result2;

	double port_array[100];
	string time_array[100];
};
#endif