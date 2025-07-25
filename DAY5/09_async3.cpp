#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
//	std::cout << "start add\n";
	std::this_thread::sleep_for(2s);
//	std::cout << "end add\n";
	return a + b;
}
int main()
{
	std::future<int> ft = std::async(&add, 1, 2); 
								
	std::cout << "continue main\n";

//	int ret = ft.get(); // 결과를 얻으려면 2초 대기 

	std::cout << "finish main\n";
	
} // <= ft 파괴
  //    소멸자 호출
  //    사용자가 get() 을 호출한적이 없으면  ft 소멸자에서 get() 호출
  //    "finish main" 출력후 2초 대기 
