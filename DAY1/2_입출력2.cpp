// 3_입출력2.cpp - 15 page아래 부분
#include <iostream>
#include <iomanip>	// 입출력 조정자(io manipulator)를 사용하기 위한 헤더

int main()
{
	int n = 10;
	std::cout << n << std::endl; // 10.  10 진수로
	std::cout << std::hex << n << std::endl; // a, 16진수로 출력
	std::cout << std::dec << n << std::endl; // 


	std::cout << std::setw(10) << n << std::endl; // 

	std::cout << std::setw(10) << std::setfill('#') << n << std::endl; // 


	double f = 3.141592;

	std::cout << f << std::endl; // 몇자리까지 나오는지 확인해 보세요
	
	// cout 출력 정밀도를 높여서 정확히 나오게 해보세요..
	// cppreference.com 에서 찾아보세요..

	// set::precision 자체는 "함수" 입니다.
	std::cout << std::setprecision(10) << f << std::endl;
}

// 해보신분은
// cppreference.com 에서 "std::setw" 검색 해보세요




