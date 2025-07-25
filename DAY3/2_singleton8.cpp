#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

public:
	// 아래 함수는 멀티스레드 안전할까요 ?
	// godbolt.org 접속후 이코드을 윈쪽에 붙여넣기 하세요
	// => C++11 이후 부터 안전. 어셈코드로 확인하시면 됩니다.
	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}



};
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}




