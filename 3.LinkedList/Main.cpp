
#include "LinkedList/LinkedList.h"

#include <iostream>
#include <forward_list>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Create a linked list.
	LinkedList<int> list;
	list.Insert(10);
	list.Insert(30);
	list.Insert(20);

	//list.Print();

	//list.Delete(30);
	//list.Delete(10);
	//
	//std::cout << "\nPrint after delete.\n";
	//list.Print();

	std::forward_list<int> stlList;
	stlList.emplace_after(stlList.begin(), 10);

	return 0;
}