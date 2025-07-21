#include <iostream>
#include <vector>

// #10. template method 패턴
// => 변하지 않은 알고리즘을 담은 메소드를 기반 클래스가 제공하고
// => 변해야 하는 부분만 가상함수로 분리해서 파생 클래스가 재정의 할수 있게
//    하는 패턴
// => 가장 널리 사용

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
public:
protected:
	void draw_imp() { std::cout << "draw rect\n"; }

public:
	virtual Rect* clone()
	{
		return new Rect(*this); 
	}	
};

class Circle : public Shape
{
public:
protected:

	void draw_imp() { std::cout << "draw circle\n"; }
public:
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


