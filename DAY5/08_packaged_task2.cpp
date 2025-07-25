#include <iostream>
#include <thread>
#include <future>

// 스레드를 고려하지 않은 일반 함수라면 아래 처럼 만들게 됩니다.
// => 이미 아래 처럼 만들어진 함수를 스레드로 수행해서 결과 얻기
int add(int a, int b)
{
	return a + b;
}

int main()
{
	// packaged_task : 멀티스레드를 고려하지 않은 함수를 멀티스로드로 
	//				  실행후 결과 얻기
	std::packaged_task<int(int, int)> task(&add);

	std::future<int> ft = task.get_future();

	// 스레드로 task 실행
	std::thread t( std::ref(task), 1, 2);

	// 결과 대기
	int ret = ft.get();

	std::cout << "result : " << ret << std::endl;
	
	t.join();

}







// promise & future : 함수인자로 promise 를 받아야 합니다
// 
// packaged_task    : 스레드 함수가 아닌 일반 함수 모양으로
//						만들어진 함수를 스레드로 수행해서 결과 얻기
//						"보관" 했다가 "원할때 실행"


