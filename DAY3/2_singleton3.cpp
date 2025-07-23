#include <iostream>

// 오직 한개의 객체가 "힙" 에 있는 모델

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	// C++17 의 inline static 문법
	// => static 멤버 데이타의 외부선언이 없어도 됩니다
	// => 단, 자기 자신을 값으로 할때는 외부선언 필요
	// => "inline static Cursor instance" 는 안됨
	inline static Cursor* sinstance = nullptr;
public:
	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
			sinstance = new Cursor;

		return *sinstance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



