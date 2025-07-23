#include <iostream>

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

	std::cout << "-----" << std::endl;
}





