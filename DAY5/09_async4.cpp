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
//	std::future<int> ft = std::async(&add, 1, 2); 

	// async 반환값을 받지 않으면
	// => async() 는 값 타입으로 반환 됩니다. => 임시객체 형태로 반환
	// => 문장의 끝에서 임시객체 파괴
	// => 임시객체의 소멸자가 get() 수행
	// => 그래서, 아래 문장은 "스레드 종료" 를 대기하게됩니다.
	// 결론 : std::async() 반드시 반환값(future) 받으세요
	std::async(&add, 1, 2); 
								
	std::cout << "continue main\n";

} 

std::future<int> async()
{
	std::future<int> ft;
	return ft;
}