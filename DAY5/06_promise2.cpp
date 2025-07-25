#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise & future 사용

// #1. 스레드 함수는 인자로 promise 를 참조로 받아야 합니다.
void add(int a, int b, std::promise<int>& pro)
{
	int s = a + b;

	std::this_thread::sleep_for(3s);

	// 연산의 결과가 나온경우 약속객체를 통해서 주스레드에 전달
	pro.set_value(s);

	// 이제 마무리 작업을 하고 종료
}



int main()
{
	// 핵심 1. 스레드가 아닌 직접 호출은 함수의 결과를 반환값으로 받으면 됩니다.
	int ret1 = add1(1, 2);

	// add1 을 스레드로 수행하면 결과를 얻을수 없습니다
	std::thread t(&add1, 1, 2);

	t.join();
}
