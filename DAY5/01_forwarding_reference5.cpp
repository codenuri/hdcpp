#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// #1. godbolt.org 에서 확인
	// #2. 생성된 함수 이름 출력
	// __func__ : 함수 이름을 담으 표준 매크로
	// __PRETTY_FUNCTION__ : 함수이름 + 인자모양 (표준 아님, g++ 전용)
	// __FUNCSIG__         : 함수이름 + 인자모양 (표준 아님, vs 전용)
	//std::cout << __func__ << std::endl;
	std::cout << __PRETTY_FUNCTION__ << std::endl;

}
int main()
{
	int n = 10;

	foo(n);  // T = int&,  foo(int& arg)
	foo(10); // T = int,   foo(int&& arg)
}




