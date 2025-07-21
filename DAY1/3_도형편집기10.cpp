#include <iostream>
#include <vector>

// 코드 정리와 생각해 볼 문제

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() {return 0;}


protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n"; 		
	}

public:
	void draw() 
	{ 
		std::cout << "mutex.lock\n"; 		

		draw_imp();
		
		std::cout << "mutex.unlock\n"; 
	}
	

	virtual Shape* clone()
	{
		return new Shape(*this); 
	}

};






class Rect : public Shape
{
protected:
	void draw_imp() override { std::cout << "draw rect\n"; }

public:
	Rect* clone() override 
	{
		return new Rect(*this); 
	}	
};

class Circle : public Shape
{
protected:

	void draw_imp() override { std::cout << "draw circle\n"; }
public:
	Circle* clone() override 
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


		// #1. 객체의 생성과정을 OCP 를 만족하게 할수 없을까요 ?
		// => 추상 팩토리 패턴을 적용하면 됩니다 - 수요일 오전

		// #2. undo/redo 기능을 넣으려면 어떻게 해야 할까요 ?
		// => command 패턴을 적용하면 됩니다 - 수요일 오전
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


