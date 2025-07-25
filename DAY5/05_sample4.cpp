#include <iostream>
#include <thread>

template<typename T> 
void foo(T a)
{

}

int main()
{
	// 함수 템플릿 사용시
	foo<int>(10); // 타입인자를 전달해도 되고
	foo(10);      // 생략해도 됩니다.(10으로 추론)

	// 하지만 foo 를 스레드로 수행하면
	std::thread t1(&foo, 10); // error. T 타입이 추론될수 없습니다.
	
	std::thread t2(&foo<int>, 10); // ok. 이렇게 해야 합니다.

	t2.join();
}