#pragma once

#include <iostream>
#include <cassert>

// iterator.
template<typename List>
class ListIterator
{
public:
	// Set Type Alias.
	// List가 template parameter로 넘어온 경우 typename까지 같이 써줘야 함.
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	ListIterator(PointerType ptr)
		:ptr(ptr)
	{

	}

	// operator overloading.

	// 전위 증가 연산자.
	ListIterator& operator++()
	{
		++ptr;
		return *this;
	}

	// 후위 증가 연산자.
	ListIterator& operator++(int)

	{
		// 현재 반복자를 임시 저장.
		ListIterator iterator = *this;

		// 내부 pointer를 ++처리.
		++(*this);

		// 앞서 지정했던 반복자 반환.
		return iterator;
	}


	// 전위 감소 연산자.
	ListIterator& operator--()
	{
		--ptr;
		return *this;
	}

	// 후위 감소 연산자.
	ListIterator& operator--(int)

	{
		// 현재 반복자를 임시 저장.
		ListIterator iterator = *this;

		// 내부 pointer를 --처리.
		--(*this);

		// 앞서 지정했던 반복자 반환.
		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(ptr + index);
	}

	PointerType operator->()
	{
		return ptr;
	}

	ReferenceType operator*()
	{
		return *ptr;
	}

	// 비교 연산자 오버로딩.
	bool operator==(const ListIterator& other) const
	{
		return ptr == other.ptr;
	}

	bool operator!=(const ListIterator& other) const
	{
		return !(*this == other);
	}

private:
	// iterator는 결국 pointer!
	PointerType ptr = nullptr;

};

// 자동으로 크기가 늘어나는 배열 (List/ Vector).
template<typename T> 
class List
{
public:
	// Set type alias.
	using ValueType = T;
	using Iterator = ListIterator< List<T> >;

public:
	List()
	{
		// 저장 공간 할당.
		ReAllocate(capacity);
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
		if (data)
		{
			memcpy(newBlock, data, sizeof(T) * capacity);
		}
		
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
		// Assert 안에는 통과가되는 조건을 넣어야한다!
		assert(index >= 0 && index < size);
		return data[index];
	}

	// Gettter.
	int Size() const { return size; }
	int Capacity() const { return capacity; }

	// 범위 기반 loop 처리를 위한 함수 작성(begin/end).
	// 배열의 첫 위치를 반환.
	//Iterator begin()
	T* begin()
	{
		//return Iterator(data);
		return data;
	}

	// 배열에 저장된 마지막 요소의 다음 위치를 반환.
	//Iterator end()
	T* end()
	{
		//return Iterator(data + size);
		return data + size;
	}

private:
	// Heap segement에 할당되는 배열을 관리할 pointer 변수.
	T* data = nullptr;

	// 배열에 저장된 항목의 수.
	int size = 0;

	// 배열 저장 공간의 크기.
	int capacity = 2;
};