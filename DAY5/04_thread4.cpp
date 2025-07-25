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
}

