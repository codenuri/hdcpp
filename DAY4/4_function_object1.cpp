#include <iostream>

// function object(함수 객체)
// => C++98 부터 있던 기술
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

// 왜 ???
// 일반함수를 만들면 되지? 함수 객체를 사용하나요 ?
// => 장점이 너무 많습니다.
// 1. Closure
// 2. 특정 상황에서 함수객체가 일반 함수보다 빠릅니다.

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;		// p 는 함수가 아닌 객체 입니다. "Plus 타입"

	int n1 = p(1, 2);	// 객체인 p를 함수 처럼 사용합니다. "함수객체"	

	int n2 = p.operator()(1, 2); // 위 코드를 이렇게 변경합니다.
								 // 직접 이렇게 호출해도 됩니다.
	
}
