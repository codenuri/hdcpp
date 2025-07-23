#include <iostream>
#include <mutex>

// tag_dispatching

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
	// m.lock()     : lock 을 획득하지 못하면 계속 대기
	// m.try_lock() : lock 을 획득하지 못하면 대기하지 않고 false 반환

	if ( m.try_lock() )
	{
		// A ......
		// B .....
		// C .....
		
		m.unlock();	// 안전하지 않습니다.
					// A ~ C 에서 문제가 발생하면 이 코드는 실행되지 않습니다.
					// lock_guard 사용하는 것이 안전 => 다음소스
	}
	else 
	{
		// lock 실패시 다른 작업.
	}
}