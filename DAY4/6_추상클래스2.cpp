// 도형편집기3 복사 해오세요 - 주석제거해 놓으세요

#include <iostream>
#include <vector>


class Shape
{
	int color;	
public:

	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};



class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Circle" << std::endl; }
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






