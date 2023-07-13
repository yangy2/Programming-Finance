//Yilin Yang
//Programming Finance Final Project

#pragma once
#ifndef BANK_ACCOUNT_YILIN_YANG_H
#define BANK_ACCOUNT_YILIN_YANG_H

#include "account_yilin_yang.h"

class Bank_Account : public Account
{
public:

	void view_balance();
	void deposit();
	void withdraw();

private:
	double depositAmount;
	double withdrawAmount;

};
#endif