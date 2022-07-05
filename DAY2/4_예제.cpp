#include <iostream>

// Swap를 만들어 봅시다.
// 1. C 버전
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 2. C++ 언어 버전
namespace utils
{
	template<typename T>
	inline void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}

int main()
{
	double x = 3, y = 2;
//	Swap(&x, &y);
	utils::Swap(x, y);

	std::cout << x << std::endl; // 2
	std::cout << y << std::endl; // 3
}



