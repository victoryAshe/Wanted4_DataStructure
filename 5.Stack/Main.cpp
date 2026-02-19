#include "Container/Stack.h"

#include <iostream>
#include <time.h>

// Random int.
int RandomRange(int min, int max)
{
	int diff = (max - min) + 1;
	return ((diff * rand())) / (RAND_MAX + 1) + min;
}

// Random float.
float RandomRange(float min, float max)
{
	float percent
		= static_cast<float> (rand())
		/ static_cast<float>(RAND_MAX);
	float diff = (max - min);
	return (percent * diff) + min;
}


int main()
{
	// Get Random Seed.
	srand(time(nullptr));

	// Create Stack.
	const int count = 10;
	Stack<float, count> stack;

	// Insert datas.
	for (int ix = 0; ix < count; ++ix)
	{
		if (!stack.Push(RandomRange(100.0f, 200.0f)))
		{
			// Exception Handling...
			std::cout << "Failed to insert value into stack.\n";
		}
	}

	// Pop value of stack and print.
	const int stackCount = stack.Count();
	for (int ix = 0; ix < stackCount; ++ix)
	{
		float value = 0.0f;
		if (stack.Pop(value))
		{
			std::cout << value << "\n";
		}
	}
	


	return 0;
}