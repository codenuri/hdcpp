#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {} 

// 정리
// "완벽한 전달" 기술을 사용하려면
// #1. 인자를 "T&&" 로 받으세요
// #2. 인자를 다른 함수에 보낼때 "std::forward<T>(arg)" 로 묶어서 전달 하세요
// => static_cast<T&&>(arg) 해도 됩니다.
// => 결국 이부분은 인자가 rvalue 일때만 요구.. 
//						 lvalue 일때는 제거 됩니다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
//	f(static_cast<T&&>(arg)); 

	f( std::forward<T>(arg) ); 	// std::forward<>() 표준 함수가 하는일이
								// 위와 동일한 캐스팅
}

int main()
{
	int n = 3;
	chronometry(foo, 10); 	
	chronometry(goo, n);	
}





