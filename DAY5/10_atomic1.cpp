#include <iostream>
#include <thread>
#include <mutex>

constexpr unsigned int cnt = 1000000;


long x = 0; // 전역변수는 모든 스레드가 공유

std::mutex m;

void foo()
{
    for (int i = 0; i < cnt; ++i)
    {
//       x = x + 1;  

		// 위 한줄은 결국 아래 3줄의 기계어 코드
		// => 여러개 스레드 수행시, 안전하게 1 증가 안됩니다.
		// mov eax, x
		// add eax, 1
		// mov x, eax

		// 해결책 #1. mutex
		std::lock_guard<std::mutex> g(m);
		x = x + 1;
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
