#include <iostream>
#include "List.h"

int main()
{
	List<int> list;
	for (int ix = 0; ix < 10; ++ix)
	{
		list.Insert(ix + 1);
	}

	// Range-based loop.
	// 아래 구문은 compiler 내부에서 pointer 연산을 자동으로 하는 것.
	std::cout << "Range-based loop.\n";
	for (const int item : list)
	{
		std::cout << item << " ";
	}
	std::cout << "\n\n";


	// loop - Iterator.
	//std::cout << "Range-based loop using Iterator.\n";
	//for (
	//	List<int>::Iterator it = list.begin();
	//	it != list.end();
	//	++it
	//	)
	//{
	//	std::cout << *it << " ";
	//}

	return 0;
}