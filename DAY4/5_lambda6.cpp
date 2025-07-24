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

	// 캡쳐의 원리
	// => 위 코드를 컴파일러가 아래처럼 변경합니다.
	class CompilerGeneratedName 
	{
		// 지역변수 캡쳐시 "멤버 데이타 추가"
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1{a}, v2{b} {}

		inline auto operator()(int a) const 
		{
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName{v1, v2};

}





