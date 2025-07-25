#include <iostream>
#include <thread>
#include <atomic>

//long x = 0;

std::atomic<long> x = 0; // 대부분의 멤버 함수가 CPU 의 명령으로
						 // 동기화

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//		x.fetch_add(1); // x = x + 1 를 CPU 명령으로 수행
      	++x; 	// 위와 동일
				// x.operator++()(long n) { fetch_add(n);}
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
