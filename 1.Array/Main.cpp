#include <iostream>
#include <cassert>
#include <array>
// Make Array using template.
template<typename T, size_t size = 10>
class Array
{
public:
	size_t Size() const
	{
		return size;
	}

	// array operator overloading.
	T& operator[](size_t index)
	{
		// 꼭 검증이 필요한 구문에 활용
		// 디버그 모드에서만 동작.
		// 많이 붙여도 상관 없음.
		//assert(index < 0 || index >= size);
		
		//if (index < 0 || index >= size)
		//{
		//	__debugbreak();
		//}

		return data[index];
	}

	//const T& operator[](size_t index) const
	//{
	//	return data[index];
	//}

private:
	// 배열 변수.
	T data[size] = {};
};

int main()
{
	Array<int, 10> array;
	
	array[3] = 20;

	// const 접근.
	//const auto& arrayReference = array;

	return 0;
}