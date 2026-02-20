#pragma once

#include "Node.h"
#include <iostream>

template<typename T>
class LinkedList
{
public:
	// 생성자.
	LinkedList()
		:first(new Node<T>()),
		last(new Node<T>()),
		count(0)
	{
		// link first <=> last node.
		first->next = last;
		last->previous = first;
	}

	~LinkedList()
	{
		// Clean memory up.
		Clear();

		delete first;
		first = nullptr;

		delete last;
		last = nullptr;
	}

	// memory 정리 함수.
	// first와 last는 제외한다.`
	void Clear()
	{
		// Data를 갖는 첫 item부터 삭제.
		Node<T>* current = first->next;

		// 마지막 노드 도달 전까지 반복.
		while (current && current != last)
		{
			// 다음 노드 임시 저장.
			Node<T>* next = current->next;

			// 현재 노드 삭제.
			delete current;

			// 다음 노드로 이동
			current = next;
		}
		
		// item count 값 정리.
		count = 0;

		// Reset to the initial state.
		first->next = last;
		last->previous = first;
	}

	// Search.
	Node<T>* Find(const T& data)
	{
		// Start to search from the first node.
		Node<T>* current = first->next;

		while (current && current != last)
		{
			// compare values.
			if (current->data == data)
			{
				return current;
			}

			// move to the next node.
			current = current->next;

		}

		std::cout << "Can't find the data.\n";
		return nullptr;
	}

	// Reverse direction Search.
	Node<T>* FindReverse(const T& data)
	{
		// Start to search from the last node.
		Node<T>* current = last->previous;

		while (current && current != first)
		{
			// compare values.
			if (current->data == data)
			{
				return current;
			}

			// move to the previous node.
			current = current->previous;

		}

		std::cout << "Can't find the data.\n";
		return nullptr;
	}

	// Insert item to the first position.
	void InsertFirst(const T& data)
	{
		// Create new node.
		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		// Pointer 정리.
		// newNode->next를 first->next로,
		// 이전 first->next의 이전 노드 (previous)를 newNode로 설정.
		Node<T>* next = first->next;
		newNode->next = next;
		next->previous = newNode;

		// first->next를 newNode로,
		// newNode->previous를 first로 설정.
		first->next = newNode;
		newNode->previous = first;

		// Add node item count.
		++count;
	}

	// Insert item to the last position.
	void InsertLast(const T& data)
	{
		// Create new node.
		Node<T>* newNode = new Node<T>();
		newNode->data = data;

		Node<T>* previous = last->previous;
		previous->next = newNode;
		newNode->previous = previous;

		newNode->next = last;
		last->previous = newNode;

		++count;
	}

	// Delete.
	void Delete(const T& data)
	{
		// Check if the list is empty.
		if (count == 0)
		{
			std::cout << "The list is empty.\n";
			return;
		}

		// Find the node to delete.
		Node<T>* deleteNode = Find(data);
		
		// Check the result is valid.
		if (!deleteNode)
		{
			std::cout << "Failed to find data to delete.\n";
			return;
		}

		// 포인터 정리.
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;
		
		// free its memory.
		delete deleteNode;
		deleteNode = nullptr;

		// subtract item count.
		--count;
	}

	void Priint()
	{
		// from the first item.
		Node<T>* current = first->next;

		std::cout << "List item count: " << count << "\n";

		while (current != last)
		{
			// print the data of the node.
			std::cout << "Item: " << current->data << "\n";
			
			// move to the next node.
			current = current->next;
		}
	}

private:
	// first Node.
	Node<T>* first = nullptr;

	// last Node.
	Node<T>* last = nullptr;

	// item count.
	int count = 0;

};