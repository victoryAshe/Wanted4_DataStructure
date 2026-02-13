#pragma once

#include "Node.h"

#include <iostream>


class Test
{
	int value;
	int* test;
};


// single linked list class.
// manges internal node.
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

	~LinkedList()
	{
		// free memory.
		NodeType current = head;
		NodeType trail = nullptr;

		// Rounding && Free memory
		while (current)
		{
			NodeType next = current->next;
			delete current;
			current = next;
		}

		// Clean-up pointer.
		head = nullptr;
		count = 0;
	}

	// Insert Node.
	void Insert(const T& data)
	{
		// Create new Node.
		NodeType newNode = new Node<T>(data);

		// Check position to insert new node.
		// Check head node is null
		if (!head)
		{
			// Set Head Node as a new node.
			head = newNode;
		}
		// Search position to insert new node.
		else
		{
			// parameter for search position.
			NodeType current = head;
			NodeType trail = nullptr; // prevNode for link to newNode.

			// Search position.
			while (current)
			{
				if (current->data >= data)
				{
					break;
				}

				// Keep searching to next node.
				trail = current;
				current = current->next;
			}

			// if the search result is the head.
			if (current == head)
			{
				// Transform the newNode as a head.
				newNode->next = head;
				head = newNode;
			}
			else // if the current is not the head.
			{
				// Make link at the searched position.
				newNode->next = current;
				trail->next = newNode;
			}
		}

		// Add item count.
		++count;
	}

	// Delete Node.
	void Delete(const T data)
	{
		//Exception Handling: if the list is empty.
		if (!head)
		{
			std::cout << "The list is empty.\n";
			return;
		}

		// Search
		NodeType current = head;
		NodeType trail = nullptr;

		// Search to the end.
		while (current)
		{
			// compare values.
			if (current->data == data)
			{
				break;
			}

			// keep searching.
			trail = current;
			current = current->next;
		}

		// Exception Handling: if the value is not in the list.
		if (!current)
		{
			std::cout << "Failed to find the node.\n";
			return;
		}

		// Delete the found node.
		// if the found node is the head.
		if (head == current)
		{
			// Set the head node as the next node. 
			head = head->next;
		}
		else // if the found is not the head.
		{
			// Move(delete) previous link of the found node(current).
			trail->next = current->next;
		}

		// free memory.
		delete current;

		// subtract item count.
		--count;
	}

	// Print.
	void Print()
	{
		// Print value rounding to the end.
		NodeType current = head;

		// Rounds.
		while (current)
		{
			// Print current data.
			std::cout << "Data: " << current->data << "\n";
			
			// Move to the next node.
			current = current->next;
		}
	}

private:
	// Heade node.
	NodeType head = nullptr;

	// item count in linked list.
	int count = 0;

};

