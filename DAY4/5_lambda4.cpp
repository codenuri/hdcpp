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

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}





