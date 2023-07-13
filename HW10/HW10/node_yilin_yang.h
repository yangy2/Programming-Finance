//Yilin Yang
//Programming Finance HW10

#pragma once
#ifndef NODE_YILIN_YANG_H
#define NODE_YILIN_YANG_H

#include <iostream>
#include <string>

using std::string;

class Node
{
	friend class LinkedList;

public:
	Node(string &name, int no) : itemName(name), itemNo(no)
	{
		this->next = NULL;
	}
private:
	string itemName;
	int itemNo;
	Node *next;
};

#endif