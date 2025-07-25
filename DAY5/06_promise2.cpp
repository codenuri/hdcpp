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
	// #2. 주스레드는 promise 객체를 만들고
	//     미래의 결과를 담은 future 객체를 꺼내 놓습니다.
	std::promise<int> pro;
	std::future<int> ft = pro.get_future();

	// #3. 스레드 생성시 promise객체를 전달합니다.
	std::thread t(&add, 1, 2, std::ref(pro));

	std::cout << "continue main\n";

	// #4. 주스레드가 다른 작업하다가 결과가 필요하면
	//		future 에서 꺼내면 됩니다.
	int ret = ft.get(); // 결과가없으면 대기
						// ft.wait(2s); 2초만 대기

	std::cout << "result : " << ret << std::endl;


	t.join();
}
