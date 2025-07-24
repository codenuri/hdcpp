#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure. 상태를 가지는 함수

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// find_if 의 3번째 인자 : 인자가 한개인 함수(단항함수)를 전달
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;	
	std::cin >> k;  // 사용자 입력

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// ? 를 어떻게 만들어야 할까요 ?
	// => foo 에 main 의 지역변수 k 를 보내야 합니다. ??!!!!
	// => 함수는 어렵습니다. 함수 객체는 쉽습니다.
	auto p2 = std::find_if(v.begin(), v.end(),  ? );

}



