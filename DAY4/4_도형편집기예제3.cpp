#include <iostream>
#include <vector>

// 핵심 3. 모든 파생클래스(도형)의 공통의 특징은 
//	       반드시 기반 클래스에도 있어야 한다.(문법적인 제약이 아니라, 디자인관점)
//         그래야지, Shape* 로 모든 도형을 묶어서 사용할때 
//         해당 특징을 사용할수 있습니다.
//		   Shape 에도 반드시 "draw"가 있어야 합니다

// 핵심 4. 기반 클래스가 가진 함수중에서 "파생클래스가 재정의" 하게 되는 것은
//		   반드시 가상함수로 만들어야 한다.(문법적 제약아니라, 디자인 관점)

class Shape
{
	int color; // 모든 도형은 색상은 있다.
public:
	// 아래 2개는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// 파생 클래스가 재정의 할필요 없습니다. => "non-virtual"
	// const Rect r; r.getColor();
	void setColor(int c) { color = c; }
	int getColor() const { return color; }

	// 모든 도형은 면적을 구할수 있습니다. 
	// 모든 도형은 면적을 구하는 방법이 다릅니다. 
	// 각 도형이 재정의 해야 합니다.
	virtual int getArea() const { return 0; }




	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw()  override { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;

		std::cin >> cmd;

		if      (cmd == 1)  v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle); 

		else if (cmd == 9)
		{
			for (auto p : v) 
				p->draw();	 
		}
	}
}



