#include <iostream>
#include <thread>

// 스레드 함수의 모양
// => ()로 호출가능한 모든것
// => 함수, 멤버함수, 함수객체, 람다 표현식등. 
void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};
struct Work
{
    void operator()(int a, double b) const {}
};

int main()
{
	std::thread t1(&foo, 1, 3.4);

	Machine m;
	std::thread t2(&Machine::Run, &m, 1, 3.4);
	
	Work w; 
//	w(1, 3.4); // 함수객체이므로 이렇게 사용가능

	std::thread t3(w, 1, 3.4);
//	std::thread t3(&w, 1, 3.4); // error. (&w)(1,3.4) 는 안됨


	std::thread t4([](){ std::cout << "lambda\n";});

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

