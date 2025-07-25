#include <iostream>
#include <thread>	// C++11 에서 추가된 스레드 관련 헤더

// #1. std::this_thread namespace 안에 도움 함수 있습니다.
int main()
{
	// 스레드 ID 구하기 
    std::cout << std::this_thread::get_id() << std::endl;

	// 주의 ) ID 는 정수 아닙니다. "std::thread::id" 라는 타입
    std::thread::id tid1 = std::this_thread::get_id();

}