#include <iostream>

// PhotoSticker 와 PhotoSticker 에 기능을 추가하는 클래스(Decorator) 는
// 동일 기반 클래스(인터페이스)가 필요 하다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class PhotoSticker : public IDraw 
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 기능 추가 클래스들은 공통의 특징이 있습니다.
// => 기반 클래스로 제공하면 편리합니다.

class Decorator : public IDraw 
{
	IDraw* oring = nullptr;
	// int x, y 등.. 공통적인 데이타
public:
	Decorator(IDraw* o) : origin(o) {}

	void draw() { origin->draw();}
};


class Emoticon  : public IDraw
{
	IDraw* origin = nullptr; 
public:	
	Emoticon(IDraw* o) : origin(o) {}

	void draw()
	{
		std::cout << "####################\n";	
		origin->draw();					
		std::cout << "####################\n";
	}
};

class Frame  : public IDraw
{
	IDraw* origin = nullptr; 
public:	
	Frame(IDraw* o) : origin(o) {}

	void draw()
	{
		std::cout << "--------------------\n";	
		origin->draw();						
		std::cout << "--------------------\n";
	}
};
int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); 
	e.draw();	

	Frame f(&e); 
	f.draw();		
}
