#include <iostream>
#include <mutex>



// 함수 오버로딩에만 사용할 타입
// => 멤버 필요 없음. empty class

class adopt_lock_t {};  // empty class

// adopt_lock_t adopt_lock; // 이렇게 하면 헤더에 넣을수 없습니다.

// 헤더에 넣으려면

constexpr adopt_lock_t adopt_lock; // 이렇게 하거나
//inline  adopt_lock_t adopt_lock; // 이렇게 하세요



template<typename T>
class lock_guard 
{
	T& mtx;
public:	
	lock_guard(T& m) : mtx(m) { mtx.lock();	}
	lock_guard(T& m, adopt_lock_t) : mtx(m) { }

	~lock_guard()             { mtx.unlock();}
};

std::mutex m;

int main()
{
	if ( m.try_lock() )
	{
//		lock_guard<std::mutex> g(m);  // 생성자에서 lock
//		lock_guard<std::mutex> g(m, adopt_lock); // lock 하지 말라	

		std::lock_guard<std::mutex> g(m, std::adopt_lock);

	}
	else 
	{

	}
}