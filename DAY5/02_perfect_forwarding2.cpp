#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 핵심 #1. int&, int&& 버전을 각각 제공해야 한다.
// 핵심 #2. 현재 코드는 1개의 문제가 있습니다. 해결은 다음 소스

void hoo(int&& arg) {} // 문제가 되는 경우


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg); 
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg); 
}

int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n); 

	hoo(10);	// ok
	chronometry(hoo, 10);  // 되야 하지만 error. 
							// 이문제만 해결하면 됩니다.

	std::cout << n << std::endl; // 10
}
