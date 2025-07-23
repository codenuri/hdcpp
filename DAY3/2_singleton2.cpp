#include <iostream>

// 1번모델 : 오직 하나의 객체가 static 지역변수
// 2번모델 : 오직 하나의 객체가 static 멤버 데이타

class Cursor
{
private:
	Cursor() {	std::cout << "Cursor\n";}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

//	Cursor instance;        // error. 자신을 멤버로 포함할수 없다.
	static Cursor instance; // ok.
public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
	std::cout << "main\n";
	
//	Cursor& c1 = Cursor::get_instance();
}




