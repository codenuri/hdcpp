#include <iostream>
#include <mutex>


template<typename T>
class lock_guard 
{
	T& mtx;
public:	
	lock_guard(T& m) : mtx(m) { mtx.lock();}
	~lock_guard()             { mtx.unlock();}
};

std::mutex m;

int main()
{
	if ( m.try_lock() )
	{
		lock_guard<std::mutex> g(m); // 버그 : 생성자가 다시 "m.lock()"
									 // 현재 mutex 는 이미 lock 상태

		// A ......
		// B .....
		// C .....
		
		//m.unlock();	
	}
	else 
	{

	}
}