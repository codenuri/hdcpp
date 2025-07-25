#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;
std::atomic<int> flag = 0;

// 아래 코드는 reodering 보장 할수 없습니다. - 잘못된 코드
/*
void foo()
{
    data1.store(100, std::memory_order_relaxed);
    data2.store(200, std::memory_order_relaxed);
    flag.store(1, std::memory_order_relaxed);
}

void goo()
{
    if ( flag.load( std::memory_order_relaxed) > 0)
    {
        assert(data1.load(std::memory_order_relaxed) == 100);
        assert(data2.load(std::memory_order_relaxed) == 200);
    }
}
*/
// release - acquire 모델
// => 특정스레드가 release 이전에 한 작업은
// => 다른 스레드의 acquire 이후에 읽을수 있어야 한다.
// => 펜스역활 + visibility 보장
// => "release" 이전 코드 끼리는 reodering 가능.
void foo()
{
    data1.store(100, std::memory_order_relaxed);
    data2.store(200, std::memory_order_relaxed);
    flag.store(1, std::memory_order_release);
}

void goo()
{
    if ( flag.load( std::memory_order_acquire) > 0)
    {
        assert(data1.load(std::memory_order_relaxed) == 100);
        assert(data2.load(std::memory_order_relaxed) == 200);
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}