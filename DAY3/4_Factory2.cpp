#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자기 자신의 객체를 생성하는 static 멤버 함수는
	// => 아주 널리 사용됩니다. 아주 좋은 기술
	static Shape* create() { return new Rect;}
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* rc = new Rect;        // 클래스 이름을 알아야 한다.
// 2. Rect* rc = Rect::create();  // 클래스 이름을 몰라도 함수주소만
//								  // 알면 객체 생성 가능  





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if ( cmd >= 1 && cmd <= 7) 
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
			
		}
	}
}




