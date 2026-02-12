#pragma once

#include <iostream>
#include <cassert>

// 자동으로 크기가 늘어나는 배열 (List/ Vector).
template<typename T> 
class List
{
public:
	List()
	{
		// 저장 공간 할당.
		//ReAllocate(capacity);
		data = new T[capacity];
		memset(data, 0, sizeof(T) * capacity);
	}

	~List()
	{
		// 자원 해제.
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}

public:
	// 저장공간 재할당하는 함수.
	void ReAllocate(int newCapacity)
	{
		// 1. 이동할 새로운 공간 할당 (new).
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. 기존 항목을 해로운 공간에 복사/이동.
		memcpy(newBlock, data, sizeof(T) * capacity);
		
		// 3. 기존 배열 공간 해제.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

	// 값 추가하는 함수.
	void Insert(const T& value)
	{
		// 크기가 부족한지 확인.
		if (size == capacity)
		{
			// 크기 재할당(2배 크기로 재할당.)
			ReAllocate(capacity * 2);
		}
		
		// 값 추가.
		data[size++] = value;
	}

	// R-value-Reference에 대한 insert.
	void Insert(T&& value)
	{
		// 크기가 부족한지 확인.
		if (size == capacity)
		{
			// 크기 재할당(2배 크기로 재할당.)
			ReAllocate(capacity * 2);
		}

		// 값을 저장할 때 이동 처리.
		data[size++] = std::move(value);
	}

	// index operator overloading.
	T& operator[](int index)
	{
		// Check range of index.
		//assert(index < 0 || index >= size);
		return data[index];
	}

	// Gettter.
	int Size() const { return size; }
	int Capacity() const { return capacity; }

private:
	// Heap segement에 할당되는 배열을 관리할 pointer 변수.
	T* data = nullptr;

	// 배열에 저장된 항목의 수.
	int size = 0;

	// 배열 저장 공간의 크기.
	int capacity = 2;
};