#pragma once
#include "Pair.h"

#include <vector>
#include <string>

// Class HashTable.
class HashTable
{
private:
	// 장황한 Type을 Entry로 치환.
	using Entry = Pair<std::string, std::string>;

public:
	HashTable();
	~HashTable();

	// Key-Value 조합으로 저장할 수 있도록.
	bool Add(const std::string& key, const std::string& value);

	// Delete: delete Key-Value data using key.
	bool Delete(const std::string& key);

	// Search.
	bool Find(const std::string& key, Entry& outEntry);

	// 출력.
	void Print();

	// Getter.
	bool IsEmpty() const;          

private:
	// 내부 저장소 크기.
	// - 내부 저장소 크기는 소수(1과 자기 자신으로만 나눠지는 수)를
	// 선택하는 것이 hash collision해시 충돌 방지에 좋음.
	// 사용 가능한 소수 중에서 큰 수를 사용.
	static const int bucketCount = 19;

	// 2차 저장소(hash collision 해결 방법으로 Chaining.)
	std::vector<Entry> table[bucketCount];
};