#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 성능을 측정하는 함수
template<typename F, typename T>
void chronomety(F f, T arg)
{
	// <========== 시간을 기록하고
	f(arg); // <== 함수 호출
	// <========== 수행시간 출력
}

int main()
{
	int n = 10;

	chronomety(foo, 10); // foo(10);
	chronomety(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
