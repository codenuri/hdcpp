// 파일 분할 -  1-1번 복사해 오세요
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0);

	void set(int a, int b);

	// 핵심 1. 상수 멤버 함수의 "const" 는 멤버 함수의 선언과 구현 에 모두
	//		  붙여야 합니다.
	void print() const;
};


Point::Point(int a, int b) : x(a), y(b) 
{
}
void Point::set(int a, int b) 
{
	x = a; 
	y = b; 
}
void Point::print() const
{
	std::cout << x << ", " << y << std::endl;
}





int main()
{
	const Point p(1, 2);

}




