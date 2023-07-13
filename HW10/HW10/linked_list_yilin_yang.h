//Yilin Yang
//Programming Finance HW10

#pragma once
#ifndef LINKED_LIST_YILIN_YANG_H
#define LINKED_LIST_YILIN_YANG_H

#include "node_yilin_yang.h"

#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	int size() const;

	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();

	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);

private:
	Node *myHead;
	Node *myTail;
	int mySize;

};
#endif