#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 객체지향으로 설계해 봅시다. - 15 page

// #1. 각 도형을 타입으로 설계한다.

class Rect 
{
	int x, y, w, h;
public:
	void draw() { std::cout << "draw rect\n"; }
};

int main()
{

}

