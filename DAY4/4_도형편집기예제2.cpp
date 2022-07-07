#include <iostream>
#include <vector>

class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;  // 크기가 없는 vector(동적배열)

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		if (cmd == 1)
		{
			// 사각형 만들기
//			Rect rc;			// 여기서 이렇게 만들면 {} 벗어날때 즉시 파괴 됩니다.
			Rect* p = new Rect;	// 사용자가 delete 할때까지는 계속 존재한다.
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle); // 이렇게 하면 결국 위와 동일 합니다.
		}
		else if (cmd == 9)
		{
			for (auto p : v) // 여기서 auto 는 Shape* 입니다. Shape* p
				p->draw();	 // error
							 // 기반 클래스로 파생 클래스를 가리킬수 있지만
							 // 파생 클래스(Rect, Circle)의 고유멤버(draw)는
							 // 접근 할수 없다.
		}
	}
}
// 이 코드는 어디서, 왜, 컴파일하면 에러가 발생 할까요 ?
// 해결책은 뭘까요?
// 1. Shape* 인 p를 "Rect*" 또는 "Circle*" 로 캐스팅한후 사용하자.
//	  => 그런데, 코드를 작성할때는 Rect 인지 Circle 인지 알수 없다.
// 
// 2. Shape 에도 draw를 만들자.  => 정답


