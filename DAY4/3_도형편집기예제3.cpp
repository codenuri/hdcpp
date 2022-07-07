#include <iostream>
#include <vector>

// 1. 모든 도형을 "타입" 으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면 
//    모든 도형을 한개의 컨테이너(vector)에 모두 보관할수 있다.
//    A 와 B를 같이 보관하고 싶다면
//    => A와 B의 공통의 기반 클래스를 만드세요!!
// 
// 핵심 3. 모든 파생 클래스의 공통의 특징이 있다면 
//        "반드시 기반 클래스에도 있어야 한다"
//		  그래야, 기반 클래스 포인터로 파생클래스들을 묶어서 관리할때
//        해당 기능을 사용할수 있다

//		  모든 도형이 그릴수(draw) 있다면, "draw" 는 
//        반드시 Shape에도 있어야 한다.

// 핵심 4. 기반 클래스의 멤버 함수중 "파생 클래스가 override" 하게 되는 
//		 모든 멤버 함수는 반드시 "virtual 함수"로 해야 한다.
//		 처음 Shape 클래스를 디자인 할때 부터 생각할수 있어야 한다.

class Shape
{
	int color;	// 모든 도형은 색상이 있다.
public:
	// 아래 멤버 함수2개는 "virtual"로 할까요 ? "non-virtual"로 할까요?
	// => 파생 클래스가 이 함수들을 "override" 할 필요는 없다.
	// => virtual 로 만들지 않아도 된다.
	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};



class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v) 
				p->draw();   
		}
	}
}




