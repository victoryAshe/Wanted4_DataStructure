#include <iostream>
#include "List.h"

int main()
{
	List<int> list;
	for (int ix = 0; ix < 10; ++ix)
	{
		list.Insert(ix + 1);
	}

	return 0;
}