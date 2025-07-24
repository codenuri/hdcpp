#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 람다표현식에서 지역변수 변경
	// => 아래 코드는 에러
//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// mutable 람다 표현식
	// => operator() 멤버 함수를 "상수함수로 하지말라"
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 

	f1(0); // v1 = 100 실행. 하지만 복사본

	std::cout << v1 << std::endl; // 10 
	
	//==================================================
	class CompilerGeneratedName 
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1{a}, v2{b} {}

//		inline auto operator()(int a) const 
		inline auto operator()(int a) 		// mutable 람다 
		{
			v1 = 100;				// () 함수가 상수 함수라면 에러
									// mutable 람다는 에러 아님
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName{v1, v2};

}





