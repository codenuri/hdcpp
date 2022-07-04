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
}
