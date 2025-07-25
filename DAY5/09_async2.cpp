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

	std::async(&add, 1, 2); 
								
	std::cout << "continue main\n";
//	int ret = ft.get();
//	std::cout << "result : " << ret << std::endl;;
}
