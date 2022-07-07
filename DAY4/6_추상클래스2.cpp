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
				p->draw();
		}
	}
}






