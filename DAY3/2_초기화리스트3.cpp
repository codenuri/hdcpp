#include <iostream>

class Point
{
public:
//	int x, y;
	int y, x;

	// 주의 : 초기화 리스트의 실행순서는 "초기화 리스트의 코드가 놓인 순서가 아니라"
	//       멤버데이타가 선언된 순서대로 실행됩니다.
	// => 되도록이면 멤버데이타가 놓인 순서대로 코드를 작성하세요.. 
	Point() : y(0), x(y)
	{
	}
};

int main()
{
	Point pt;

	std::cout << pt.x << std::endl; // ?
	std::cout << pt.y << std::endl; // ?
}




