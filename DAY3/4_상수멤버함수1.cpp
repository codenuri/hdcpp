// 4_상수멤버함수1.cpp    119 page ~
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 컴파일러는 "멤버함수 호출이 가능한지" 여부를 판단할때, 함수 선언부만을 가지고
	// 판단합니다.
	// 아래 처럼 만들면 "print()" 안에서 멤버의 값을 변경할수도 있다고 판단합니다.
	// => 그래서 상수객체는 아래 멤버 함수를 호출할수 없습니다.
	void print() 
	{	
		std::cout << x << ", " << y << std::endl;
	}
};

int main() 
{
//	Point p(1, 2);

	// 핵심 : p는 "상수 객체" 입니다.
	const Point p(1, 2);

	// p가 상수라는 것을 기억하고, 아래 3줄을 생각해 보세요.
	p.x = 10;		// error. x는 public에 있지만, p가 상수객체이므로
	p.set(10, 20);	// error. 
	p.print();		// error.
}




