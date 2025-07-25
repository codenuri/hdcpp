﻿#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자
void draw_line(const Point& from, const Point& to) {}

int main()
{
	// (1, 1) ~ (5,5) draw_line() 으로 선을 그리고 싶다.

	Point p1{1, 1};
	Point p2{5, 5};
	draw_line(p1, p2); 
	// => 함수 호출뒤 더이상 p1 , p2 가 필요없습니다.
	// => 즉시 파괴될까요 ?

	// 인자로만 사용하는 객체는 "temporary" 로 하는것이 맞습니다.!!
	// => 가장 좋은 코드
	draw_line(Point{1, 1}, Point{5,5});

	std::cout << "-----" << std::endl;
}





