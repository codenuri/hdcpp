#include <iostream>
#include <vector>

// #2. 기반 클래스가 있다면
// => 모든 도형의 공통의 특징을 한곳에서 관리할수 있고
// => 모든 도형의 객체를 하나의 컨테이너에 보관 가능한다

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 만 보관 가능한 컨테이너
	std::vector<Shape*> v; // 모든 도형을 보관 가능한 컨테이너
							// <== 객체지향 디자인의 핵심!!!

}

