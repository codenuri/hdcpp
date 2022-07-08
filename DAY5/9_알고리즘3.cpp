// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

	// 주어진 구간에서 처음 나오는 "3" 을 찾아라
	auto ret1 = std::find(v.begin(), v.end(), 3); 

	// 주어진 구간에서 처음 나오는 "3의 배수" 을 찾아라
	// std::find    : 값   검색, 3번째 인자가 값 전달
	// std::find_if : 조건 검색, 3번째 인자가 함수 전달
	auto ret2 = std::find_if(v.begin(), v.end(), foo );

	std::cout << *ret2 << std::endl; // 9


	// 람다 표현식(C++11)
	// 함수 이름(주소)가 필요한 자리에 함수 구현 자체를 전달하는 표현식
	// => 요즘에 많이 사용됩니다.
	// [] : 람다 표현식이 시작됨을 알리는 "lambda introducer"

	auto ret3 = std::find_if(v.begin(), v.end(), 
							[](int n) { return n % 3 == 0; } );

}