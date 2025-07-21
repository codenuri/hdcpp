#include <iostream>
#include <vector>

// 해결책 #2 - 좋은 디자인

// #4. 모든 파생클래스(도형)의 공통의 특징은 기반 클래스(Shape)에도 있어야 한다.
// => 그래야 Shape* 로 해당 기능을 사용할수 있다.


class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw Shape\n"; }
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
				s->draw(); 
		}
	}
}


