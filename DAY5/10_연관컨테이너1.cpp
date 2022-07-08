#include <iostream>
#include <algorithm>

// 선형 컨테이너3개
#include <vector>
#include <list>
#include <deque>

// 연관 컨테이너 4개
#include <set>	
#include <unordered_set>
#include <map>
#include <unordered_map>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// set : RB Tree 로 구현된 컨테이너
	// 그런데... 왜 이름이 "set" 인가요 ?
	// => 집합 관련 기능을 제공합니다.(교집합, 합집합등)
	std::set<int> s = { 50, 30, 70, 60, 20, 40, 80 };

//	s.push_back(75); // error.
				     // set 은 insert로만 넣을수 있습니다.

	s.insert(75); // ok. root 부터 크기 비교해서 넣기

	auto p = s.begin(); // 제일왼쪽 자식
	*p = 100; // error. 
			  // set의 반복자는 읽기 전용입니다.

	// 결론 : 자료구조의 특징을 잘알고 있어야 합니다.
}