#include <iostream>

// 1번모델 : 오직 하나의 객체가 static 지역변수
// 2번모델 : 오직 하나의 객체가 static 멤버 데이타

// static 멤버 데이타 : 전역변수와 동일합니다.
//					   get_instance()를 호출하지 않아도 객체생성(생성자호출)
//					   main 함수 실행전에 생성저 호출됨
//						"빠른(early) 초기화"
// 
// static 지역변수 : 늦은(lazy) 초기화
//	   				get_instance()를 최초 호출시 객체 생성
//					get_instance()를 호출하지 않으면 생성자 호출 안됨.


class Cursor
{
private:
	Cursor() {	std::cout << "Cursor\n";}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

//	Cursor instance;        // error. 자신을 멤버로 포함할수 없다.
//	static Cursor instance; // ok.
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
//Cursor Cursor::instance;

int main()
{
	std::cout << "main\n";

	Cursor& c1 = Cursor::get_instance();
}




