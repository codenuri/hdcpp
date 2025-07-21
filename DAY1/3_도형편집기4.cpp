#include <iostream>
#include <vector>

// #3-1. 해결책 #1. 캐스팅
// => 아래 코드는 에러 없이 예상대로 잘동작합니다.

// 그런데!!!
// => 새로운 도형 Triangle 이 추가되면


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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triange\n"; }
};


int main()
{
	std::vector<Shape*> v; 

	while( true )
	{
		int cmd;
		std::cin >> cmd;

		if      ( cmd == 1 ) v.push_back( new Rect);
		else if ( cmd == 2 ) v.push_back( new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
			{
				/*
				Rect* r;
				Circle* c;

				if ( r = dynamic_cast<Rect*>(s) != nullptr )
				{
					r->draw();
				}
				*/
				// 위 코드는 C++17 에서 나온 새로운 if 문을 사용하면 편리
				// if (초기화 구문 ; 조건식 )
				if ( Rect* r = dynamic_cast<Rect*>(s); r != nullptr )
				{
					r->draw();
				}
				else if ( Circle* c = dynamic_cast<Circle*>(s); c != nullptr )
				{
					c->draw();
				}
			}
		}
	}
}


