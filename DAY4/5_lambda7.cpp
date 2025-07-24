#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 람다표현식에서 지역변수 변경
	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	
	
	//==================================================
	class CompilerGeneratedName 
	{
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





