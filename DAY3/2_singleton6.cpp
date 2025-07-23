#include <iostream>
#include <mutex>

// RAII 패턴
// => 자원 해지는 함수의 마지막 부분에서 하면 안된다. => 안전하지 않다.
// => 생성자/소멸자에 의존해라!

template<typename T>
class lock_guard 
{
	T& mtx;
public:	
	lock_guard(T& m) : mtx(m) { mtx.lock();}
	~lock_guard()             { mtx.unlock();}
};



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	inline static std::mutex m;
	inline static Cursor* sinstance = nullptr;
public:

	static Cursor& get_instance()
	{
		m.lock();

		if ( sinstance == nullptr )
			sinstance = new Cursor;

		// 여기서 예외가 발생하거나
		// if(실패) return ; // 나중에 이런 실수를 하면
						     // 아래 문장은 실행될수 없다.
		m.unlock();

		return *sinstance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



