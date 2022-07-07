// 예제1     152 page
#include <iostream>
#include <vector>

// 핵심 1. 각 도형을 타입화 하면 편리하다.

// 핵심 2. 모든 도형의 공통의 기반 클래스가 있다면
//         모든 도형을 하나의 컨테이너(vector)에 보관할수 있다.

class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; // 모든 종류의 도형을 보관할수 있다.
}



