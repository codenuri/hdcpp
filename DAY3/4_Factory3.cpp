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
// => main 함수 이전에 실행
// => 즉, 아래 코드 때문에 main 이전에 이미 공장에 Rect 등록됨
// AutoRegister ar(1, &Rect::create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect;}

	// static 멤버 데이타의 특징을 생각해 보세요
	// => 언제 생성되는가 ?
	// => 최초 1회 - 아래 주석 참고
	// => 주의 클래스 안에서 객체 만들때 () 사용시 에러
	//     {} 사용하세요. 
	inline static AutoRegister ar{1, &Rect::create};
};



/*
// C#  
class Car 
{
	public Car() {}
	public static Car() {} // 정적 생성자
}

Car c1 = new Car(); // 1. 정적 생성자 호출
					// 2. 생성자 호출
Car c2 = new Car(); // 생성자
Car c3 = new Car(); // 생성자
*/
// 생성자 : 객체의 초기화
// 정적 생성자 : 클래스 자체의 초기화

// 위 Rect 클래스
//						// Rect::ar 생성자 - 최초 1회만 => 공장 등록
// Rect* r1 = new Rect; // Rect 생성자
// Rect* r2 = new Rect; // Rect 생성자
// Rect* r3 = new Rect; // Rect 생성자




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle;}

	inline static AutoRegister ar{2, &Circle::create};	
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




