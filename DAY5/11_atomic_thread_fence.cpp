#include <atomic>

// -O2 옵션이 있을때와 없을 때의 차이점 중요

// 아래 코드를 godbolt.org 넣어보세요
#include <atomic>

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

//    asm("mfence");
    std::atomic_thread_fence(std::memory_order_seq_cst);

    b = 1;
}
// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ?
    }
}

// 멀티스레드시에 고려할것은 3가지
// 1. 동시접근
// 2. reordering (순서 변경)
// 3. visibility (캐쉬가 아닌 메모리에 실제 쓰였는가 ?)





