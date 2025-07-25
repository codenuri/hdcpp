#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
	std::cout << "start add\n";
	std::this_thread::sleep_for(2s);
	std::cout << "end add\n";
	return a + b;
}
int main()
{
//	std::future<int> ft = std::async(&add, 1, 2); 

	// 아래 처럼 만들면 "동기 실행" 처럼 보이게 됩니다.
	// => 그런데, 스레드 생성 맞습니다. 
	std::async(&add, 1, 2); 
								
	std::cout << "continue main\n";
//	int ret = ft.get();
//	std::cout << "result : " << ret << std::endl;;
}
