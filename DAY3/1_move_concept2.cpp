#include <iostream>
#include <string>
#include <vector>

// 왜 move 가 중요한가 ?

// 아래 코드는 복사에 의한 Swap
// => 느립니다
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a; 
	a = b;
	b = tmp;
}
*/
// move 에 의한 swap
// => 위 swap 보다 아주 빠릅니다
// => 현재 C++ 표준 swap 은 아래 처럼 구현
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a); 
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";
	Swap(s1, s2);
}

// move 에서 알아야 하는 것
// #1. swap, 버퍼 복사 등의 알고리즘 작성시
// => std::move() 를 사용하면 빨라집니다.
// => 쉬운편

// #2. string이 아닌 우리가 만든 클래스가 move 를 지원하려면 어떻게해야하는가?
// => 어렵고 복잡한 이야기..


