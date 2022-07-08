// 4_STL_컨테이너1.cpp - 216
#include <iostream>
#include <vector>

int main()
{
	// 배열   : 크기를 변경할수 없다. 연속된 메모리
	// vector : 크기를 변경할수 있다. 연속된 메모리, 배열과 사용법 거의 동일
	int x[5] = { 1,2,3,4,5 };

	std::vector<int> v = { 1,2,3,4,5 };



	// 배열과 vector 는 사용법이 거의 동일 합니다.
	std::cout << x[0] << std::endl; // [] 연산자 사용가능
	std::cout << v[0] << std::endl; // [] 연산자 사용가능




	// 하지만 vector 가 배열 보다 편리합니다.
	v.resize(10);


	std::cout << v.size() << std::endl; // 10
}