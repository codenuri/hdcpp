#include <iostream>
#include <mutex>


template<typename T>
class lock_guard 
{
	T& mtx;
public:	
	// lock()을 하지 않은 버전의 생성자 필요!!
	// 어떻게 만들까요 ??
	// 방법 #1. bool 를 사용한 flag
	lock_guard(T& m, bool flag = true) : mtx(m) 
	{ 
		if ( flag == true)
			mtx.lock();
	}
	~lock_guard()             { mtx.unlock();}
};

std::mutex m;

int main()
{
	if ( m.try_lock() )
	{
//		lock_guard<std::mutex> g(m); // 버그 : 생성자가 다시 "m.lock()"
									 // 현재 mutex 는 이미 lock 상태

		lock_guard<std::mutex> g(m, false);	// ok						  

		// A ......
		// B .....
		// C .....
		
		//m.unlock();	
	}
	else 
	{

	}
}