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

// 공장에 도형을 자동 등록하는 코드를 매크로화 합니다.
#define REGISTER(key, classname)							\
	static Shape* create() { return new classname;}			\
	inline static AutoRegister ar{key, &classname::create};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 아래 번호는 좀더 발전시키면 생략가능합니다.
	// 공장에서 번호를 얻으면 됩니다. 
	REGISTER(1, Rect)
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	// 이 클래스를 공장에 등록하라는 의미
	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(3, Triangle)
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




