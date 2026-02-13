#include "LinkedList.h"
#include "Node.h"
#include <iostream>

int main()
{  
	LinkedList<int> list;
	for (int ix = 0; ix < 10; ++ix)
	{
		list.InsertLast((ix + 1) * 10);
	}

	std::cout << "리스트 추가 후 출력\n";
	list.Priint();

	// delete items
	list.Delete(20);
	list.Delete(50);
	list.Delete(60);

	std::cout << "리스트 삭제 후 출력\n";
	list.Priint();

	return 0;
} 