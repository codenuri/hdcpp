#include <iostream>

/*
int Add(int a, int b)
{
	return a + b;
}
*/

// Add 같은 경우는 "함수" 보다 "함수 템플릿(틀)" 로 제공하는 것이 좋다.
template<typename T> 
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << Add(1,   2 )  << std::endl;
	std::cout << Add(1.1, 2.2) << std::endl;

	// 아래 코드가 정확한 표기법이지만, 타입인자 생략가능하므로
	// 위처럼 사용가능
	std::cout << Add<int>(1, 2) << std::endl;
}

