#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

int main()
{
	// #1. 현재 스레드 재우기
//  std::this_thread::sleep_for(3); // error
									// 인자는 정수가 아닌
									// chrono 클래스
	std::chrono::seconds s{3};
	std::this_thread::sleep_for(s); // ok
	std::this_thread::sleep_for(std::chrono::seconds{3}); // ok

	// 아래 같이 3s, 3ms 등을 사용하려면
	// => using namespace std::literals;
	std::this_thread::sleep_for(3s);
	std::this_thread::sleep_for(3ms);
	std::this_thread::sleep_for(3min);
}

