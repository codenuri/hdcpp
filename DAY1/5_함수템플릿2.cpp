#include <iostream>

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << Add(1, 2)   << std::endl; // int

	std::cout << Add(1, 2.2) << std::endl; // error.
						// 함수인자를 보고 타입을 추론할수 없습니다.

	std::cout << Add<double>(1, 2.2) << std::endl; // ok

	// 결론. 위처럼 템플릿을 만들면
	// 1. 1, 2 번째 인자가 다른 타입이면 항상 타입인자를 전달해야 하고
	// 2. 생성된 함수는 항상 1, 2번째 인자가 같은 타입입니다.
}

