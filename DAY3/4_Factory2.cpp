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

// C++에서 클래스이름을 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); <= 클래스 이름이 아닌 문자열 보관한것

// 하지만 함수 포인터는 보관 가능
// v.push_back(&Rect::create); // ok
//								// 이 정보로 객체 생성가능.
								// 결국 클래스 이름을 보관 한것


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle;}
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape*(*)();

	std::map<int, CREATOR> create_map; // <번호, 생성함수> 보관

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
			p = ret->second(); // ret->second 는 value 즉, 생성함수
		}

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




