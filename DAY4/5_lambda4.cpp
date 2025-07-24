#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// 핵심 모든 람다표현식은 다른 타입이다.

	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy{};

	// 람다 표현식 사용시 컴파일러가 만드는 클래스 이름 확인
	// 1. 아래 처럼 확인
	// 2. godbolt.org  확인 - operator()도 볼수 있습니다. gcc
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}





