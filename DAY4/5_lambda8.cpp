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

	f3(0);

	std::cout << v1 << std::endl; // 100

	//==================================================
	class CompilerGeneratedName 
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1{a}, v2{b} {}

		inline auto operator()(int a) const
		{
			v1 = 100;				
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName{v1, v2};

}





