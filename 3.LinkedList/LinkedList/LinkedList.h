#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
	// Set Type Alias.
	using NodeType = Node<T>*;


public:
	LinkedList()
		:head(nullptr), count(0)
	{

	}

private:
	// Heade node.
	NodeType head = nullptr;

	// item count in linked list.
	int count = 0;

};

