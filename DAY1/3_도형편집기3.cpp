#include <iostream>
#include <vector>

// #3. 왜 에러일까요 ?

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
				s->draw(); // 여기서 에러. 
						   // 원인 : s 는 Shape* 인데, Shape 에는 draw가 없다.
						   // 해결책은 다음소스에서 
		}
	}
}
// 위 코드는 어디서 ?? 왜 에러일까요 ??
// 최선의 해결책은 뭘까요 ?

