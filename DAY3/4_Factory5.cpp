#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect;}

	Rect* clone() override { return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle;}

	Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map; 

public:
	void register_shape(int key, Shape* c)
	{
		prototype_map[key] = c;
	}



	Shape* create(int type)
	{
		Shape* p = nullptr;
		
		auto ret = prototype_map.find(type);

		if ( ret != prototype_map.end() )
		{
			p = ret->second->clone(); // prototype 
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품(도형)을 등록해야 합니다.
	// => 결국 생성함수를등록하므로 "클래스이름" 등록의 효과
	// => 객체를 생성하기 위해 등록 하므로
	// factory.register_shape(1, &Rect::create);
	// factory.register_shape(2, &Circle::create);

	// 공장에 자주 사용되는 제품의 견본을 등록합니다
	// => "코딩시 자주 사용하는 코드 snip 했다 쓰는 것처럼"

	Rect* red_rect = new Rect; // 생성과정이 복잡한 빨간색 제품
	Rect* blue_rect = new Rect; 
	Circle* red_circle = new Circle; 

	factory.register_shape(1, red_rect);
	factory.register_shape(2, blue_rect);
	factory.register_shape(3, red_circle);



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




