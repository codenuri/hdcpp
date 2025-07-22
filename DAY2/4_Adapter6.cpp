#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// C++11 에서 등장한 "range-for"
	// 아래 코드의 원리는 ?
	for( auto e : v)
	{
		std::cout << e << std::endl;
	}

	// 위코드를 컴파일러가 아래 코드로 변경
	auto first = v.begin();		// v가 배열이면 auto first = v;
	auto last  = v.end();		//  		   auto last = v + 10

	for( ; first != last; ++first)
	{
		auto e = *first;
		//----------------
		std::cout << e << std::endl;
	}
}
