// C++20 의 1번째로 뽑히는 기술 
// concept1.cpp
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void foo(T& t)
{
	t.resize(10);
}

int main()
{	
	int n = 10;
	std::vector<int> v = {1,2,3,4,5};
	
	foo(v); // ok
	foo(n); // ?
}

