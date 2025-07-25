// C++20 의 1번째로 뽑히는 기술 
// concept1.cpp
#include <iostream>
#include <string>
#include <vector>

template<typename T>
concept has_resize = requires(T& c)
{
	c.resize(0);
	c.begin();
	c.end();
};

// C++은 "타입에 따른 함수 오버로딩을 제공합니다."
void foo(int a) {}
void foo(double a) {}

// 타입이 아닌 조건에 따른 오버로딩을 할수 없을까요 ?
// => resize()함수가 있는 타입과 없는 타입
void goo( resize가 있는 타입 ){}
void goo( resize가 없는 타입 ){}


int main()
{	
	std::vector<int> v = {1,2,3,4,5};
	
	foo(v); // ok
}
