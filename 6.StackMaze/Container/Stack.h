#pragma once

// Class DataStructure Stack.
template<typename T, int capacity = 10>
class Stack
{
public:
	// 생성자.
	Stack()
		:top(0)
	{
	}

	// 추가 함수.
	bool Push(const T& value)
	{
		// if Stack is Full: fails.
		if (IsFull())
		{
			return false;
		}

		// Save.
		data[top] = value;
		++top;
		return true;
	}

	// 삭제 함수.
	// 고민해볼 사항. 반환 값을:
	// 1. 성공/실패 여부로 할지
	// 2. stack의 삭제된 값으로 할 지.

	// 1번 방법으로 구현.
	bool Pop(T& outValue)
	{
		// if Stack is empty: fails.
		if (IsEmpty())
		{
			return false;
		}

		// Pop value.
		--top;
		outValue = data[top];
		return true;
	}

	// Getter.
	inline int Count() const { return top; }

	// Check stack is empty.
	inline bool IsEmpty() const { return top == 0; }

	// Check stack is full.
	inline bool IsFull() const { return top >= capacity; }

private:
	// Clear the stack.
	void Clear()
	{
		top = 0;
	}

private:
	// Manage the stack with a static array
	T data[capacity] = {};

	// Value points the top of the stack.
	int top = 0;
};