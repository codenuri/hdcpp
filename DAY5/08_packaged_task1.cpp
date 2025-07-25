#include <iostream>
#include <thread>
#include <future>

// 멀티 스레드를 위해 설계된 함수
// => 아래처럼 promise 등을 인자로 받게 됩니다.

// 핵심 : 아래 add 는 처음부터 만들때 멀티스레드를 위해서 설계된것
void add(std::promise<int>& p, int a, int b)
{
	p.set_value(a + b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::ref(pm), 10, 20);

	int ret = ft.get();

	t.join();
}



