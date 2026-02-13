#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList;

public:
	// »ý¼ºÀÚ.
	Node()
		: data(data), next(nullptr), previous(nullptr)
	{
	}


private:
	// data field.
	T data;

	// link field: next
	Node<T>* next = nullptr;

	// link field: prev
	Node<T>* previous = nullptr;
};