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
// => size 에 따라 오버로딩

template<typename T>
concept big_size = sizeof(T) >= 8;

template<typename T>
concept small_size = sizeof(T) < 8;

void goo( big_size auto a ) { std::cout << "big size\n";}
void goo( small_size auto a ){ std::cout << "small size\n";}


int main()
{	
	double d = 0;
	int n = 0;
	goo(d);
	goo(n);
}
