#include <iostream>
#include <algorithm>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

// unordered_set

int main()
{
//	std::set<int> s;			// tree, 모든 요소가 정렬을 유지 한다.
	std::unordered_set<int> s;	// hash, 정렬 유지 안함

	// set 과 unordered_set 의 사용법은 거의 동일 합니다.
	s.insert(50);	
	s.insert(30);
	s.insert(70); // s가 set 이면 root 부터 비교해서 왼쪽/오른쪽으로 배치
		// unordered라면 hash 함수에 보내서 저장할 index를 얻은후 보관



}