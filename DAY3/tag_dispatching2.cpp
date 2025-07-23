#include <iostream>
#include <mutex>

// 아래와 같은 flag 사용의 단점
// lock_guard<std::mutex> g(m, false);
// 1. false 의 의미가 명확하지 않다.
// 2. false 대신 "0, 1, 2" 등의 다른 표현도 가능
// 3. if 문에 따른 성능저하


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