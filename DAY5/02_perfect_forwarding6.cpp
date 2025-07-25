#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {} 

// 한개가 아니라 여러개를 완벽한 전달하려면
// => 가변 인자 템플릿 기술로해야 합니다.
// => ... 을 3곳에만 표기 

// 인자가 2개라면
// => 아래 처럼 3곳이 추가
// => 변하는 곳의 패턴이 정해져 있습니다.
/*
template<typename F, typename T1, typename T2>
void chronometry(F f, T1&& arg1, T2&& arg2)
{
	f( std::forward<T>(arg1), std::forward<T>(arg2)  ); 	
}
*/
// ... : 가변인자 템플릿 기술
// => chronometry(함수, arg1, arg2) 	 : 위처럼 2개 받도록
// => chronometry(함수, arg1, arg2, arg) : 3개 받도록
// => chronometry(함수) 				 : 이 것도 가능
template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... ); 	
}

int main()
{
	int n = 3;
	chronometry(foo, 10); 	
	chronometry(goo, n);	
}





