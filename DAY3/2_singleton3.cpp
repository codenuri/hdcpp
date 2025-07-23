#include <iostream>

// 오직 한개의 객체가 "힙" 에 있는 모델

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	static Cursor* sinstance;
public:
	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
			sinstance = new Cursor;
		
		return instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



