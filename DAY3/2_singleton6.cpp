#include <iostream>
#include <mutex>

// RAII 패턴
// => 자원 해지는 함수의 마지막 부분에서 하면 안된다. => 안전하지 않다.
// => 생성자/소멸자에 의존해라!


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

		m.unlock();

		return *sinstance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



