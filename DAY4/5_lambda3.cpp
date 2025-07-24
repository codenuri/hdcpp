#include <iostream>

// auto 와 람다 표현식
int main()
{
//	컴파일러가만든클래스이름 f = [](int a, int b) { return a + b; };
				// class xxx{ operator()() {} }; xxx{};

	// 람다표현식은 auto 변수에 담아서 함수처럼 사용해도 됩니다.
	// => 원리는 위 코드
	// => 결국 f 는 
	// => "CompilerGeneratedName f" 의 코드. 즉, f는 객체
	auto f = [](int a, int b) { return a + b; };

	int n1 = f(10,20);

	std::cout << n1 << std::endl; // 30
}

