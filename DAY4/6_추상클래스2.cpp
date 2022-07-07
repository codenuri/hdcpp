// 도형편집기3 복사 해오세요 - 주석제거해 놓으세요

#include <iostream>
#include <vector>

class Shape
{
	int color;	
public:
	// 핵심 1.기반 클래스는 반드시 소멸자를 가상함수로
	virtual ~Shape() {} 

	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	// 핵심 2. 가상함수 vs 순수 가상함수
	// 
	// 일반 가상함수 : 파생클래스가 override 하지 않으면 기본 구현을 물려주겠다는것
	// 순수 가상함수 : 파생클래스가 반드시 override 해야 한다는것 

	// 또한, "도형"은 추상적인 개념이다. "그릴수"는 없다..
//	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	// 현재 코드에서는 "draw"는 순수 가상함수가 되는게 맞습니다.
	virtual void draw() = 0; 
};

class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Triangle" << std::endl; }
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
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw(); // 다형성(polymorphism)
							// => 동일한 표현식이 상황(객체)에 따라
							//    다르게 동작하는 것
							
			// 객체지향의 3대 특징 : 캡슐화, 상속성, 다형성

			// 다형성의 장점 : 나중에 새로운 도형이 추가되어도
			//				"p->draw()" 는 수정될 필요 없다.
			// 
			//	"새로운 요소가 추가되었는데, 기존 코드가 수정되지 않는다"!!
		}
	}
}
// 파생 멤버함수에 virtual 적으면 파생의 파생만들 때 영향을 끼치는 걸까요?
// => 네 맞습니다.!! 





