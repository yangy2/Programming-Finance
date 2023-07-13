//Yilin Yang
//Programming Finance HW10

#include <iostream>
#include <stdio.h>

#include "node_yilin_yang.h"
#include "linked_list_yilin_yang.h"

using std::cout;
using std::endl;
using std::string;

LinkedList::LinkedList() : myHead(0), myTail(0)
{
	mySize = 0;
}

LinkedList::~LinkedList() 
{
	if (size() != 0)
	{
		Node *current = myHead;
		Node *garbage;

		while (current != 0)
		{
			garbage = current;
			current = current->next;
			delete garbage;
		}
	}
}

int LinkedList::size() const
{
	return mySize;
}

void LinkedList::addToStart(Node *node)
{
	if (size() == 0) myHead = myTail = node;
	else
	{
		node->next = myHead;
		myHead = node;
	}
	mySize++;
}

void LinkedList::addToEnd(Node *node)
{
	if (size() == 0) myHead = myTail = node;
	else
	{
		myTail->next = node;
		myTail = node;
	}
	mySize++;
}

void LinkedList::printList()
{
	Node *current = myHead;

	cout << "\tITEM NO \tITEM NAME" << endl;
	
	while (current != 0)
	{
		cout << "\t" << current->itemNo << "\t\t" << current->itemName << endl;
		current = current->next;
	}
}

bool LinkedList::removeFromStart()
{
	if (size() == 0) return false;
	else
	{
		Node *garbage = myHead;

		if (myHead == myTail) myHead = myTail = 0;
		else myHead = myHead->next;

		delete garbage;
		mySize--;

		return true;
	}
}

bool LinkedList::removeFromEnd()
{
	if (size() == 0) return false;
	else
	{
		Node *garbage = myTail;
		if (myHead == myTail) myHead = myTail = 0;
		else
		{
			Node *current = myHead;
			while (current->next != myTail) current = current->next;

			myTail = current;
			current->next = 0;
		}

		delete garbage;
		mySize--;

		return true;
	}
}

void LinkedList::removeNodeFromList(int number)
{
	if (size() == 0) return;
	
	Node *previous = NULL; 
	Node *garbage = NULL;

	if (myHead->itemNo == number)
	{
		garbage = myHead;
		myHead = garbage->next;
		delete garbage;
		mySize--;
		cout << "\tItem Number " << number << " was deleted" << endl;
		return;
	}

	previous = myHead;
	garbage = myHead->next;

	while (garbage != NULL)
	{
		if (garbage->itemNo == number)
		{
			previous->next = garbage->next;
			if (garbage == myTail) myTail = previous;
			delete garbage;
			mySize--;
			cout << "\tItem Number " << number << " was deleted" << endl;
			break;
		}

		previous = garbage;
		garbage = garbage->next;
	}
	if (garbage == NULL) cout << "\tItem not found" << endl;
}

void LinkedList::removeNodeFromList(string name)
{
	if (size() == 0) return;
	
	Node *previous = NULL;
	Node *garbage = NULL;

	if (myHead->itemName == name)
	{
		garbage = myHead;
		myHead = garbage->next;
		delete garbage;
		mySize--;
		cout << "\tItem named '" << name << "' was deleted" << endl;
		return;
	}

	previous = myHead;
	garbage = myHead->next;

	while (garbage != NULL)
	{
		if (garbage->itemName == name)
		{
			previous->next = garbage->next;
			if (garbage == myTail) myTail = previous;
			delete garbage;
			mySize--;
			cout << "\tItem named '" << name << "' was deleted" << endl;
			break;
		}

		previous = garbage;
		garbage = garbage->next;
	}
	if (garbage == NULL) cout << "\tItem not found" << endl;
}
