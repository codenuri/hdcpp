#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id) {}

int main()
{
    // 핵심 1. 스레드를 만들면 반드시 join(), detach() 해야 합니다.
    std::thread t1(&do_work, 1);
    t1.join();

    // 핵심 2. 10개의 스레드를 생성해 봅시다.

	std::vector<std::thread> v;

	for( int i = 0; i < 10; i++)
	{
		// 방법 #1. std::thread 객체 만들어서 move로 넣기
//	    std::thread t(&do_work, 1);
//		v.push_back(t); // error. 복사 될수 없다.
//		v.push_back(std::move(t)); // ok

		// 방법 #2. 임시객체
		// v.push_back( std::thread{&do_work, 1} ); // ok

		// 방법 #3. emplace_back - 제일 좋은 방법
		v.emplace_back( &do_work, 1);    	
	}

	// 주스레드 종료전 모든 스레드 대기
	for( auto& t : v)
		t.join();
}
