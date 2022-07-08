// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
//	std::list<int>   c = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };


//	auto p1 = c.begin(); 
//	auto p2 = c.end();
// 
	// 역반복자 ( reverse iterator ) 꺼내기.
	auto p1 = c.rbegin(); // 마지막에서 1번째(10)를 가리키는 반복자
	auto p2 = c.rend();   // 제일 앞보다 한개 앞..
	
	// ++p1; reverse 반복자는 거꾸로동작 합니다. 9를 가리키도록 변경

	while (p1 != p2)
	{
		std::cout << *p1 << ", ";
		++p1;
	}
	std::cout << std::endl;

}

