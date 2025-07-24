#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

//	auto f1 = [v1, v2](int a)         { v1 = 100; return a + v1 + v2; }; // error
//	auto f2 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok

	// 레퍼런스 캡쳐
	// v1, v2 를 복사본이 아닌 참조로 보관합니다.
	auto f3 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; }; 

	f3(0); // "v1 = 100" 에서 v1 은 main 지역변수 의 참조 

	std::cout << v1 << std::endl; // 100

	//==================================================
	// 참조 캡쳐의 원리
	class CompilerGeneratedName 
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1{a}, v2{b} {}

		inline auto operator()(int a) const
		{
			v1 = 100;		// v1 이 레퍼런스이므로
							// 이 코드는 v1을 변경한것이 아니라
							// v1 이 가리키는 곳을 변경한것
							// 의미상으로 "*v1 = 100" 
							// 그래서 "상수멤버함수" 라도 변경 가능

			return a + v1 + v2;
		}
	};
	auto f4 = CompilerGeneratedName{v1, v2};

}





