#include <iostream>

class Point
{
	int x, y;
public:
	Point()				: x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	// 사용자가 만든 코드	// 컴파일러가 변경한 코드
	Rect()				// Rect() : ptFrom(), ptTo()  처럼 변경한것
	{					// => 기계어로는 call Point::Point()
		std::cout << "Rect()" << std::endl;
	}
};
int main()
{
	// 생성자가 호출되는 정확한 원리
	// 1. Rect 를 만들면 Rect의 생성자가 호출되는 기계어 코드 생성
	Rect r;  // call Rect::Rect() 
}




