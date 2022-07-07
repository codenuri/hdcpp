// 예제1     152 page
#include <iostream>
#include <vector>

class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
//			Rect rc; // 이렇게 만들면 {} 벗어날때 바로 파괴 됩니다.
//			v.push_back(&rc);
			v.push_back(new Rect); // 이렇게 만들어야 {} 벗어나도 파괴되지 않습니다.
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v) // Shape* p 인데
				p->draw();   // 그런데, Shape에는 draw 멤버 함수가 없다.
		}
	}
}
// 위 코드는 왜 에러일까요 ??
// 해결책은 뭘까요 ??
// 1. Shape* p 를 Rect* 나 Circle* 로 캐스팅한후 사용하자
//    => 그런데, 코드를 작성할때는 p가 가리키는 곳이 Rect 인지 Circle 인지 알수없다

// 2. Shape 에도 draw를 만들자 => 정답



