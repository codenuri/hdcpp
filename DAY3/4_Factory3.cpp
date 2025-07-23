#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

// ShapeFactory 를 Rect 위로 이동. 
class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
	using CREATOR = Shape*(*)();
	std::map<int, CREATOR> create_map; 
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;
		auto ret = create_map.find(type);
		if ( ret != create_map.end() )
		{
			p = ret->second(); 
		}
		return p;
	}
};

// 공장에 제품을 등록할때 사용할 클래스

class AutoRegister
{
public:
	AutoRegister(int key, Shape*(*c)() )
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각하세요
AutoRegister ar(1, &Rect::create);




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect;}
};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle;}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품(도형)을 등록해야 합니다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




