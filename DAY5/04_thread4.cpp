#include <thread>

// copy, move

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

	// #1. swap
//	t1.swap(t2); // ok


	// #2. copy, move => 아주 중요합니다.

//	std::thread t3 = t1; 			// error
	std::thread t4 = std::move(t2); // ok

    t1.join();
    t4.join();

	// 
	// std::thread 객체만 미리 만들어도 됩니다.
	std::thread t5;     // 아직 함수 전달 안함. 아직 스레드는 생성안됨
//	t5 = std::move(t1); // 이렇게 가능
}

