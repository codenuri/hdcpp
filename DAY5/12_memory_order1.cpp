#include <thread>

int x = 0;
int y = 0;

// 아래 코드는 동기화 없습니다.
// => 동시접근도 보장될수 없습니다.

void foo()
{
    int n1 = y;
    x = n1;
}
void goo()
{
    int n2 = x;
    y = 100;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}