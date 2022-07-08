// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
	//	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. 반복자를 꺼내고 사용
	auto p1 = s.begin();

	// p1이 s의 1번째 요소를 가리키는 반복자 입니다.
	// 이제 p1을 포인터 처럼 생각하고 사용하세요.
	*p1 = 10;
	std::cout << *p1 << std::endl; // 10

	++p1;
	std::cout << *p1 << std::endl; // 2


	// 2. 반복자의 정확한 타입 - 약간 복잡합니다.
	// => 아래 코드를 알아는 두세요.
	// => 그런데, 실전에서는 auto 사용하세요
	// 1. 코드가 복잡해 보이고
	// 2. 컨테이너 교체시 아래 코드도 수정되어야 합니다.
	std::list<int>::iterator p2 = s.begin();
};




/*
namespace std
{
	template<typename T>
	class list
	{
	public:
		class iterator
		{
		};
	};
}
*/