#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;

// std::memory_order_seq_cst
// => 모두 보장해 달라
// => 반드시 순차적 실행, visibility 도 보장, 동시접근도 보장

int main()
{
    data1.store(100, std::memory_order_seq_cst);
    data2.store(200, std::memory_order_seq_cst);
    data2.store(300); // 생략시 위와 동일

	data2 = 400; // 위와 동일 

	// 결국 "std::atomic<>" 변수의 =, ++ 등의 연산은
	// => 3개를 모두 보장 

	data2 = 100; // 이렇게 하면 되는데
	data2.store(100); // 왜 이렇게 하나요 ?
					  // memory_order 변경하고 싶을때...
					  // 2번째 인자로!
}