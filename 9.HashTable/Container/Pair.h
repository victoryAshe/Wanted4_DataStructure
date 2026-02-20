#pragma once

// key-value 쌍을 저장할 때 사용할 자료형.
template<typename KeyType, typename ValueType>
class Pair {
public:
	KeyType key;
	ValueType value;

	Pair()
		:key(), value()
	{
	}

	Pair(const KeyType key, const ValueType value)
		:key(key), value(value)
	{
	}

	//operator overloading.
	bool operator== (const Pair<KeyType, ValueType>& other)
	{
		// 전제조건: key와 value가 각각 comparable해야 함.
		return key == other.key && value == other.value;
	}

	bool operator!=(const Pair<KeyType, ValueType>& other)
	{
		// 위와 같은 전제조건을 가짐.
		return !(*this == other);
	}

	bool operator>(const Pair<KeyType, ValueType>& other)
	{
		return key > other.key;
	}

	bool operator<(const Pair<KeyType, ValueType>& other)
	{
		return key < other.key;
	}

	bool operator>=(const Pair<KeyType, ValueType>& other)
	{
		return key >= other.key;
	}

	bool operator<=(const Pair<KeyType, ValueType>& other)
	{
		return key <= other.key;
	}
	
};