// 189page
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};
std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << pt.x << ", " << pt.y;
	return os;
}

int main()
{
	Point p(1, 2);

	std::cout << p ; // cout.operator<<(Point) 가 필요 하다.
					 // => cout 은 ostream 타입인데.. 우리가 만든 클래스가 아니다.
					 // => 멤버 함수를 추가할수는 없다.

					 // 멤버 함수가 안되면, 일반함수로 하면 된다.
					 // => operator<<(cout, p)
					 // => operator<<(ostream, Point) 를 만들면 된다.
					  

}


