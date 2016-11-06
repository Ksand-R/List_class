// my_list.cpp : Defines the entry point for the console application.
// шаблонный класс список

#include "stdafx.h"
#include"_List.h"

int main()
{
	_List<int> l1;
	l1.add_el_in_head(3);
	l1.add_el_in_head(4);
	l1.add_el_in_head(5);

	l1.Print_list();
	cout << endl;
	l1.del_el_fr_tail();
	//l1.del_node();
	//l1.Print_list();
	int A;
	int* a = &A;
	cout << a << endl;
	l1.find_ptr(4);

	return 0;
}

