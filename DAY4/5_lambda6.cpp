// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수 사용
	auto f1 = [](int a) { return a + g; }; 		// ok


	// #2. 람다표현식에서 지역변수 사용
	// => 아래처럼은 안됨
//	auto f2 = [](int a) { return a + v1 + v2; }; // error


	// #3. 람다표현식에서 지역변수 사용하려면 캡쳐해야 합니다.
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; 


}





