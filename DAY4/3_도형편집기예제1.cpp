// 예제1     152 page
#include <iostream>
#include <vector>

// 1. 모든 도형을 "타입" 으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면 
//    모든 도형을 한개의 컨테이너(vector)에 모두 보관할수 있다.
//    A 와 B를 같이 보관하고 싶다면
//    => A와 B의 공통의 기반 클래스를 만드세요!!

class Shape
{
};

class Rect : public Shape
{
	// 멤버 데이타와 생성자는 생략
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 객체만 보관 가능한 vector
	std::vector<Shape*> v; // 모든 도형 객체를 보관 할수 있는 vector
}



