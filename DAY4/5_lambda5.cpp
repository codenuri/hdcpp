#include <iostream>

int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// return 문장이 한개이거나, 또는 여러개 문장이 같은 타입 반환시
	// 생략가능
	auto f2 = [](int a, int b) { return a + b; };
	auto f3 = [](int a, int b) { if( a == 1 ) return a; return a + b; };

	// 아래 코드는 에러
	auto f4 = [](int a, double b) { if( a == 1 ) return a; return a + b; };

	// 아래 코드는 에러 아님
	auto f5 = [](int a, double b) -> double { if( a == 1 ) return a; return a + b; };

}

