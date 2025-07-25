// C++20 의 1번째로 뽑히는 기술 
// concept1.cpp
#include <iostream>
#include <string>
#include <vector>

// #1. 타입이 가져야하는 규칙을 정의하는 개념(concept)을 설계 합니다.
template<typename T>
concept has_resize = requires(T& c)
{
	c.resize(0);
	c.begin();
	c.end();
};

/*
template<typename T> requires has_resize<T> 
void foo(T& t)								
{
	t.resize(10);
}
*/
// 위 코드는 아래 처럼 간단히 가능
template<has_resize T> 
void foo(T& t)								
{
	t.resize(10);
}

// 위와 동일 
void goo(has_resize auto t)								
{
	t.resize(10);
}


int main()
{	
	std::vector<int> v = {1,2,3,4,5};
	
	foo(v); // ok
}
