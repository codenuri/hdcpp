// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
//	std::list<int>   c = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너 모든 요소 열거하는 방법
	// 1. range - for 문, 모든 컨테이너 가능, C++11 부터

//	for (auto  e : c)
	for (auto& e : c)  // 값을 변경하려면 참조로!
	{
		std::cout << e << ", ";
	}
	std::cout << std::endl;



	// 2. 반복자 사용, 모든 컨테이너 사용가능 
	// => C++98 시절에 널리 사용되던기술
	// => C++11 이후에는 위 코드가 더 널리 사용

	auto p1 = c.begin();

	while (p1 != c.end())
	{
		std::cout << *p1 << std::endl;
		++p1;
	}

	// 3. [] 연산자 사용 - vector, deque만 가능, list 안됨
	for (int i = 0; i < c.size(); i++)
	{
		std::cout << c[i]; // c가 list 라면 에러.
	}
}

