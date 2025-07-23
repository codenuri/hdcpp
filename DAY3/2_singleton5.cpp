#include <iostream>
#include <mutex>

// DCLP 개념 과 문제점

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	inline static std::mutex m;
	inline static Cursor* sinstance = nullptr;
public:

	// 아래 함수가 100번 호출 될때를 생각해 보세요
	// 최초 호출      : 객체 생성
	// 이후 99번 호출 : 생성된 객체의 반환만 
	//					하지만 lock/unlock 을 수행하게 됩니다.
	/*
	static Cursor& get_instance()
	{
		m.lock();
		if ( sinstance == nullptr )
			sinstance = new Cursor;
		m.unlock();

		return *sinstance;
	}
	*/
	// 해결책 : 2번의 if 문
	// 최초 호출 : 
	// 이후 호출 : 
	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
		{
			m.lock();
			if ( sinstance == nullptr )
				sinstance = new Cursor;
			m.unlock();
		}

		return *sinstance;
	}

};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



