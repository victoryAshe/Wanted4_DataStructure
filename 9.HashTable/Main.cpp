#include "Container/HashTable.h"

#include <iostream>

int main()
{
	// Create HashTable Instance.
	HashTable table;

	// Add Data.
	table.Add("Ronnie", "010-1234-5678");
	table.Add("Ronnie", "010-1234-5678");
	table.Add("Ashe", "010-1234-5678");
	table.Add("Ranie", "010-1234-5678");

	// Print.
	table.Print();

	// Search.
	Pair<std::string, std::string> outValue;
	if (table.Find("Ranie", outValue))
	{
		std::cout
			<< "검색 성공. Key: " << outValue.key
			<< "| Value: " << outValue.value << "\n";
	}

	return 0;
}