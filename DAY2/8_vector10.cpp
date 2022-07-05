#include <iostream>
#include <vector> // 이미 C++ 표준에 vector가 있습니다.
				  // 우리가 만든것보다 훨씬 잘 만든... 

int main()
{
	int x[5]; // 배열은 크기를 변경할수 없습니다.

	std::vector<int> v(5, 0);

	// 배열과 vector는 사용법이 동일합니다.
	x[0] = 10;
	v[0] = 10; // 표준의 vector는 [] 연산 가능


	// 그런데, vector는
	// 1. 크기 변경 가능
	// 2. 수많은 편리한 멤버 함수 제공
	v.resize(20);

	std::cout << v.size() << std::endl;
}
// std::vector 와 같이 표준이 제공하는 것을 STL이라고 합니다.
// "Standard Template Library"


