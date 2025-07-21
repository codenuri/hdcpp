#include <iostream>
#include <vector>

// 가상함수 vs 순수 가상함수

class not_implemented{};

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
	void draw() 
	{ 
		std::cout << "mutex.lock\n"; 		

		draw_imp();
		
		std::cout << "mutex.unlock\n"; 
	}


	void set_color(int c) { color = c;}


	// 가상함수      : override 하지 않으면 기본 구현 제공할것 이라는 의도
	// 순수 가상함수 : 반드시 만들라는 의미

	// "Shape" 는 추상적 개념
	// => "draw_imp" 의 기본 구현을 제공할수는 없다.
protected:
	virtual void draw_imp() = 0;

public:

	// clone 은
	// #1. = 0 으로 해도 좋습니다. 엄격하고 안전한 코드
	// => 하지만 순수가상함수가 너무 많으면 파생클래스가 해야할 작업이 많습니다.
	// => clone()이 자주 사용되는 함수가 아니면 2번도 가능
	// virtual Shape* clone() = 0;


	// #2. 기본 구현에서 예외 발생
	// => clone 을 override 하지 않고 사용하지 않으며 => ok
	// => clone 을 override 하지 않고 사용하면 => 예외 발생
	// => clone 을 override 하고 사용하면 => ok

	// 의도 : 필요하면 만들라는 것
	// => C#, Python 에서 많이 사용
	// => 안전성이 부족하다.
	virtual Shape* clone()
	{
		throw not_implemented(); 
	}

	// #1, #2 도 좋은데,, C 스타일의 기본 구현은 잘못된 값 반환도
	// 역시 널리 사용됩니다.
	// 도움말 : get_area() 호출시 0이 나오면 "면적구할수 없음" 이라고 약속
	virtual int get_area() {return 0;}
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


