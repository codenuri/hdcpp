#include <iostream>
#include <vector>

// #7.


class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() {return 0;}

	virtual void draw() { std::cout << "draw Shape\n"; }
	

	// 자신의 복사본을 생성하는 가상함수는 아주 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		return new Shape(*this); // 자신(*this) 를 복사해서 생성
	}

};






class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	// 참고 :가상함수 override 시 반환 타입 변경 가능합니다.(단, 상속관계타입만)
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

			// 이제 조사할 필요없이 요청하면 됩니다.
			v.push_back( v[k]->clone() );

			// 자바같은 언어 에서 이런 개념을 아래와 같이 표현합니다. 의미 생각해보세요
			// "Don't Ask Do It"
	
		}
	}
}


