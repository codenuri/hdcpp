#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// #1. godbolt.org 에서 확인
	// #2. 생성된 함수 이름 출력
	std::cout << __func__ << std::endl;

}
int main()
{
	int n = 10;

	foo(n);  // T = int&,  foo(int& arg)
	foo(10); // T = int,   foo(int&& arg)
}




