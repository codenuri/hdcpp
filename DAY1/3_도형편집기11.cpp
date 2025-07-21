#include <iostream>
#include <vector>

// 가상함수 vs 순수 가상함수

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



protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n"; 		
	}

public:


	virtual Shape* clone()
	{
		return new Shape(*this); 
	}

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


