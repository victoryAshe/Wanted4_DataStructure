#include "Container/Queue.h"

#include <iostream>

int main()
{
	// Create Queue Instance.
	Queue<int> queue;
	const int count = 10;
	for (int ix = 0; ix < count; ++ix)
	{
		queue.Enqueue(ix + 1);
	}

	// Print.
	queue.Print();

	// Extract Values.
	int value;
	for (int ix = 0; ix < 3; ++ix)
	{
		queue.Dequeue(value);
	}
	queue.Print();


	// Add Value.
	for (int ix = 11; ix < 15; ++ix)
	{
		queue.Enqueue(ix);
	}
	queue.Print();


	return 0;
}