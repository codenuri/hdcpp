#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>  // 이 안에 이미 take_view, reverse_view 같은 어답터가
					// 30개 이상있습니다.
					// 중첩도 됩니다.   C++20, -std=c++20

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	using namespace std::views;

	auto odd = [](int n) { return n % 2 == 1;};

//	for( auto e : std::views::take(v, 5)) 
//	for( auto e : reverse(take(v, 5))) 
//	for( auto e : filter(reverse(take(v, 5)), odd) )  // 이표기를

	for( auto e : v | reverse | take(5) | filter(odd) )  // 이표기로도
	{													// 가능.
		std::cout << e << std::endl;
	}

}
