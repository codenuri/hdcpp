//  5_연산자재정의 - 182(131) page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }

	// 멤버함수로 구현한 operator+ 함수 (함수이름이 "operator+" 입니다.)
	Point operator+(const Point& pt)
	{
		std::cout << "member operator+" << std::endl;

		Point temp(x + pt.x, y + pt.y);
		return temp;
	}

};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);


	Point p3 = p1 + p2;   // 1. p1.operator+(p2) 가 있으면 사용
						  // 2. operator+(p1, p2) 가 있으면 사용
						  // 둘다 없다면 컴파일 에러..

}

