#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	std::vector<int> v = {1,2,3,4};

	// 아래 코드의 문제점 찾으세요
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );
}





