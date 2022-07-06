#include <iostream>

class Car
{
	int speed;
public:
	// 다음중 에러는 ?
	// this            : 멤버 함수를 호출할때 사용한 객체
	// static 멤버 함수 : 객체 없이 호출가능
	void foo()
	{
		speed = 10;
		std::cout << this << std::endl; // 1
	}
	static void goo() 
	{
		speed = 10;
		std::cout << this << std::endl; // 2
	}
};
int main()
{
	Car c;
	c.foo();
	
	Car::goo();
	c.goo();
}
