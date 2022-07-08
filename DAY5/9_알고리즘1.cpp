// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너에서 3을 찾고 싶다.
	// 방법 1. 멤버함수 find를 제공하자.
	// => 특징 : 모든 컨테이너에 find 함수가 있어야 한다
//	s.find(3); // error. 이런 멤버 함수는 없습니다.
//	v.find(3);

	// 방법 2. 멤버 함수가 아니라 일반 함수 find를 제공하자.
	// 장점 : find 같은 함수 한개로 모든 컨테이너에 사용
	// 알고리즘 : std::find 같이 멤버가 아닌 함수를 "알고리즘"이라고 합니다.
	auto ret1 = std::find( s.begin(), s.end(), 3 );
	auto ret2 = std::find( v.begin(), v.end(), 3 );

	// find 반환값
	// 검색 실패시 : 2번째인자로 전달한 반복자(s.end()) 반환
	//      성공시 : 찾은 요소를 가리키는 반복자 
	
	if (ret2 == v.end())
	{
		std::cout << "검색 실패" << std::endl;
	}
	else
	{
		std::cout << "검색 성공" << std::endl;
		int n = *ret2;
		// 반복자는 포인터와 유사하므로 - 로 하면 index 얻을수 있습니다.
		std::cout << (ret2 - v.begin()) + 1 << std::endl;
	}
}