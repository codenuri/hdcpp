#include <iostream>

class Point
{	
public:
	int x, y;
	Point(int a, int b) x:{a}, y{b} {}	
};

int main()
{
	Point pt{1,1};

	// reference 규칙 - 중요합니다. 외우세요!!
	// 규칙 #1. non-const reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;			// ok
	Point& r2 = Point{1, 1};// error

	// 규칙 #2. const reference 는 lvalue, rvalue 모두 가리킵니다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point{1, 1};	// ok

	// 규칙 #3. rvalue reference 는 rvalue 만 가리킬수 있다.
	// => C++11 에서 move 만들기 위해 추가한 문법
	Point&& r1 = pt;			// error
	Point&& r2 = Point{1, 1};	// ok

}







