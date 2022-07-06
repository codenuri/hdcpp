#include <iostream>

class Car
{
	int speed;
public:
	// 다음중 에러는 ?
	// this            : 멤버 함수를 호출할때 사용한 객체
	// static 멤버 함수 : 객체 없이 호출가능
	void foo()		// void foo(Car* this)	  즉, non-static 멤버함수는 this 추가
	{
		speed = 10;	//	this->speed = 10;		ok

		std::cout << this << std::endl; // 1	ok
	}

	static void goo()	// void goo()  즉, static 멤버함수는 this 추가 안됨.
	{
		speed = 10;	// this->speed = 10 으로 변경해야 하는데
					// this가 없습니다. 그래서 컴파일 에러
					// "static 멤버함수는 static 멤버만 접근 된다" 라는 문법의 이유

		std::cout << this << std::endl; // 2. error
	}
};

int main()
{
	Car c;
	c.foo();	// foo(&c)
	
	Car::goo();	// goo()
	c.goo();	// goo()
}
