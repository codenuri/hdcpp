// 2_복사생성자1.cpp - 92 page
#include <iostream>

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2

	// 사용자가 만들지 않으면 컴파일러가 아래 모양의 
	// 복사 생성자를 제공합니다.
	// => 모든 멤버 데이타를 복사 해줍니다.
	// 복사 생성자 : 자신과 동일한 타입의 객체 한개를 인자로 가지는 생성자
//	Point(const Point& p) : x(p.x), y(p.y) {}
};


int main()
{
	// 아래 4줄에 대해서 생각해 봅시다.
	Point p1;		// ok.		1번 생성자 호출
//	Point p2(1);	// error.	Point(int) 모양의 생성자는 없다.
	Point p3(1,2);	// ok.		2번 생성자 호출

	Point p4(p3);   // ok.      Point(Point) 모양의 생성자가 필요하다.
					// => 자신과 동일한 타입의 객체 한개를 인자로 가지는 생성자
					// => 사용자가 만들지 않으면 컴파일러가 제공
}