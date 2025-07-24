#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	std::vector<int> v = {1,2,3,4};

	// 아래 코드의 문제점 찾으세요
	// => 아래 코드는 sort() 함수가 3개 생성됩니다.
	// => 그런데, 3개 모두 비교정책이 동일
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );

	// 아래 코드는 sort() 함수가 1개 생성됩니다.
	// => 동일한 람다 표현식이 여러번 사용되면 auto 변수에 담아서 사용하세요
	auto cmp = [](int a, int b) { return a < b;} ;
	std::sort(v.begin(), v.end(), cmp );
	std::sort(v.begin(), v.end(), cmp );
	std::sort(v.begin(), v.end(), cmp );

	// 그런데, < 가 필요하면
	// => std::less 사용하는 것이 더 좋을수 있습니다.
	std::sort(v.begin(), v.end(), std::less{} );
	std::sort(v.begin(), v.end(), std::less{} );
	std::sort(v.begin(), v.end(), std::less{} );
}





