#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
//  foo();	// 주스레드가 호출

	// #1. 스레드 생성
	std::thread t(&foo);  // 이순간 스레드가 생성되어서 foo 실행
						  // "t.start()" 같은 함수 호출 필요 없음

	std::cout << "주스레드는 계속 실행\n";

	// #2. 스레드 생성시
	// => 자식 스레드 종료를 대기하거나
	// => 자식 스레드를 분리해야 합니다.
	t.join();   // 종료 대기
//	t.detach(); // 스레드 분리

	std::cout << "주스레드 종료\n";
}

