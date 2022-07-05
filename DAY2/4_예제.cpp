#include <iostream>
#include <algorithm> // 이 헤더에 이미 std::swap 가 있습니다.

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
//	utils::Swap(x, y);
	std::swap(x, y); // C++ 표준 함수는 모두 소문자 입니다.

	std::cout << x << std::endl; // 2
	std::cout << y << std::endl; // 3
}

// 여러 파일에서 같은 이름의 namespace 로 각자 정의도 되나요?
// => 네 가능합니다.
// a.h(.cpp)
namespace utils
{
}
// b.h(.cpp)
namespace utils // 이름이 같아도 충돌 아닙니다. 합쳐 지게 됩니다.
{
}

