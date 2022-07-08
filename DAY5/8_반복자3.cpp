#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 1. past the end

	auto p1 = s.begin(); // 1번째 요소
	auto p2 = s.end();   // 마지막 요소가 아닙니다. 
						 // 마지막 다음을 가리킵니다.(past the end)

	*p1 = 10; // ok
//	*p2 = 10; // runtime error. end()로 얻은 반복자는 * 하면 안됩니다.

	// s.end()로 얻는 반복자는 == 와 != 연산에만 활용해야 합니다.
	while (p1 != p2)
	{
		std::cout << *p << std::endl;
		++p1;
	}
}