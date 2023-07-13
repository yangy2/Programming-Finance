//Yilin Yang
//Programming Finance Final Project

#pragma once
#ifndef NODE_YILIN_YANG_H
#define NODE_YILIN_YANG_H

#include <string>

using std::string;

class Node
{
	friend class Stock_Account;

public:
	Node(string &s, int n) : symbol(s), price(n)
	{
		this->next = NULL;
		this->previous = NULL;
	}

private:
	Node *next;
	Node *previous;

	string symbol;
	int price;

};
#endif