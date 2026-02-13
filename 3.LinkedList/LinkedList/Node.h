#pragma once

// Data field, link field를 갖는 Node class.
// item for Linked List.
template<typename T>
class Node
{
	// Set Linked List as friend.
	template<typename T>
	friend class LinkedList;

	// Node Creation은 Linked List에서만 가능하도록 private으로 접근지정.
private:
	Node()
		:data(), next(nullptr)
	{}

	Node(T data)
		:data(data), next(nullptr)
	{
	}

private:
	// data field.
	T data;

	// link field.
	Node* next = nullptr;
};