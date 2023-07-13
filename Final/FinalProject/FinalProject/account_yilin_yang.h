//Yilin Yang
//Programming Finance Final Project

#pragma once
#ifndef ACCOUNT_YILIN_YANG_H
#define ACCOUNT_YILIN_YANG_H

using std::string;

class Account
{
public:

	void refresh_cin();
	double get_balance();
	void set_balance(double);
	virtual void write_history(string, double);
	virtual void print_history();

protected:

	double balance;
};
#endif