#include <iostream>

int g = 10;

class Point
{
public:
	int x = 0;
	int y = ++g;

	Point() {}
	Point(int a) : y(a) {}
};
int main()
{
	Point p1;
	Point p2(1);
	std::cout << g << std::endl; // 결과 예측해 보세요
								// 앞의 원리를 잘 생각해 보세요
								// 1. 10   2. 11   3. 12
}