#include <iostream>
#include <algorithm>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

int main()
{
	std::set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(70);

//	s.push_back(10);  // error. insert만 가능

	auto p1 = s.begin();
	*p1 = 200;  // error. 반복자는 읽기만 가능
				

	// 아래 코드는 실행되지만 좋지 않습니다.
	auto ret = std::find(s.begin(), s.end(), 30); // ?

	

}