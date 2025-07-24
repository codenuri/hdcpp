// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 아래 코드의 원리
	// => 람다표현식은
	// => 함수객체를 만드는 표기법입니다.
	// => 람다표현식의 최종결과는 "임시객체(이름없는객체)" 입니다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });


	// 위 코드를 컴파일러가 아래 처럼 변경합니다.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const 
		{
 			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );



}





