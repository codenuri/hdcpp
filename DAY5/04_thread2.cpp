#include <iostream>
#include <string>
#include <thread>

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

     // 인자 전달 방법
	 std::thread t1(&f1);
	 std::thread t2(&f2, 1, 3.4);
	 std::thread t3(&f3, 1, std::ref(n), std::move(s));

     // => 핵심 : reference 로 보내려면 "std::ref(n)" 으로
	 //          스레드간에 지역변수는 공유 아주 위험합니다.
	 //			 반드시 필요한 경우만 주의해서 사용하세요

	 t1.join();
	 t2.join();
	 t3.join();

}

