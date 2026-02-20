#pragma once

#include <iostream>

// class Queue: FIFO.
template<typename T, int capacity = 10>
class Queue
{
public:
	Queue()
	{
	}

	// Add.
	bool Enqueue(const T& value)
	{
		// Fails if the queue is full.
		if (IsFull())
		{
			return false;
		}

		// Add +) index out of range could not be happened.
		rear = (rear + 1) % (capacity + 1);
		data[rear] = value;
		return true;
	}


	// Data extraction.
	bool Dequeue(T& outValue)
	{
		// Fails if the queue is empty.
		if (IsEmpty())
		{
			return false;
		}

		// index out of range could not be happened.
		front = (front + 1) % (capacity + 1);
		outvalue = data[front];

		// data initialize.
		data[front] = T();
		// memset(&data[front], 0 , sizeof(T)));
		return true;
	} 

	// Return the front value without delete it.
	bool Peek(T& outValue)
	{
		// Fails if the queue is empty.
		if (IsEmpty())
		{
			return false;
		}

		outValue = data[(front + 1) % (capaccity + 1)];
		return true;
	}

	// Print.
	void Print()
	{
		std::cout << "Print Queue data: ";

		// print.
		const int max = (front < rear) ?
			rear : (rear + (capacity + 1));
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << " " << dat[ix % (capacity + 1)];
		}

		// Finish.
		std::cout << "\n";
	}

	// Getter.
	inline bool IsEmpty() const { return rear == front; }
	inline bool IsFull() const
	{
		return ((rear + 1) % (capacity + 1)) == front;
	}

	inline int Capacity() const { return capacity; }

private:

	// position value to insert data.
	int front = 0;

	// position value to delete data.
	int rear = 0;

	//  data container.
	T data[capacity + _ 1] = {};
};