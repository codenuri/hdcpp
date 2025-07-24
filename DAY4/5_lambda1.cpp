// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional> // C++98. std::less<> 등..
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	// #1. 비교정책 전달안하면 오름 차순
	std::sort(v.begin(), v.end()); 


	// #2. 비교 정책으로 "일반함수" - 인라인 치환 안됨
//	std::sort(v.begin(), v.end(), cmp1); 


	// #3. 인라인치환(빠르게) 하려면 함수 객체로
	std::less<int> f1;
	std::greater<int> f2;

	std::sort(v.begin(), v.end(), f1); 

	std::sort(v.begin(), v.end(), std::less<int>());  // C++98
	std::sort(v.begin(), v.end(), std::less<int>{});  // C++11
	std::sort(v.begin(), v.end(), std::less<>{});     // C++17
	std::sort(v.begin(), v.end(), std::less{});       // C++20


	// #4. 람다 표현식 사용 - C++11
	std::sort(v.begin(), v.end(),  [](int a, int b) { return a < b;});

}





