#include <iostream>
#include <vector>

// #6. 다형성(polymorphism) 개념


class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() {return 0;}

	virtual void draw() { std::cout << "draw Shape\n"; }
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
	void draw() { std::cout << "draw Triangle\n"; }
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
				s->draw(); // 다형성(polymorphism)
						   // => 동일한 코드가 상황(실제 객체)에 따라
						   // => 다르게 동작하는 것
						   // => "Triangle" 이 추가되어도 이코드는
						   //    수정될 필요 없다.
						   // => OCP 를 만족하는 좋은 디자인
						   
				// 객체지향 프로그램의 3대 요소
				// => 캡슐화, 상속, 다형성

			}
		}
	}
}


