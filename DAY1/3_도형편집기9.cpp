#include <iostream>
#include <vector>


class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() {return 0;}



	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않는 코드 내부에 숨은 변하는 코드는 분리 되어야 한다.
	// => 변하는 것을 가상함수로 분리한다

	virtual void draw_imp()
	{
		
	}

	virtual void draw() 
	{ 
		std::cout << "mutex.lock\n"; 
		
		std::cout << "draw Shape\n"; 

		std::cout << "mutex.unlock\n"; 
	}
	

	virtual Shape* clone()
	{
		return new Shape(*this); 
	}

};






class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	virtual Rect* clone()
	{
		return new Rect(*this); 
	}	
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

	virtual Circle* clone()
	{
		return new Circle(*this); 
	}	
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
				s->draw(); 

			}
		}
		else if (cmd == 8 )
		{
			std::cout << "몇번째 도형을 복제할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() );
	
		}
	}
}


