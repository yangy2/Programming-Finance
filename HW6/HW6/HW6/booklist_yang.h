#pragma once
//Yilin Yang
//Programming Finance HW6

#pragma once
#ifndef BOOKLIST_H
#define BOOKLIST_H

class Booklist
{

private:
	bool sorted = false;

public:
	int list[20] = { 0 };

	void refresh_cin();
	int check(int list[]);
	int getISBN();
	int getPosition();
	void print_list(int list[]);
	void insert_at(int list[], int entry, int position);
	int linear_search(int list[], int entry);
	int binary_search(int list[], int left, int right, int entry);
	void delete_at(int list[], int entry, int position);
	void selection_sort(int list[]);
	void bubble_sort(int list[]);
	int print_menu();

	bool get_sort_status() { return sorted; }

};
#endif // !BOOKLIST_H