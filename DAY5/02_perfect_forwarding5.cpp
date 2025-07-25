#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {} 

// 정리
// "완벽한 전달" 기술을 사용하려면
// #1. 인자를 "T&&" 로 받으세요
// #2. 인자를 다른 함수에 보낼때 "?" 하세요
// 

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg)); 
}

int main()
{
	int n = 3;
	chronometry(foo, 10); 	
	chronometry(goo, n);	
}





