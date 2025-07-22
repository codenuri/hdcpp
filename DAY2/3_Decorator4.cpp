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
	IDraw* origin = nullptr;
	// int x, y 등.. 공통적인 데이타
public:
	Decorator(IDraw* o) : origin(o) {}

	void draw() { origin->draw();}
};


class Emoticon  : public Decorator
{ 
public:	
	Emoticon(IDraw* o) : Decorator(o) {}
	void draw()
	{
		std::cout << "####################\n";	
		Decorator::draw();					
		std::cout << "####################\n";
	}
};
class Frame  : public Decorator
{ 
public:	
	Frame(IDraw* o) : Decorator(o) {}

	void draw()
	{
		std::cout << "--------------------\n";	
		Decorator::draw();						
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
/*	
	// A. 그냥.. 아래 처럼하면 안되나요 ?
	PhotoSticker p;
	p.take();
	p.draw(); // 필터 없는 그림
	p.add_filter(new EmoticonFilter);
	p.add_filter(new FrameFilter);
	p.draw(); // 원래 그림그리고, 등록된 필터의 draw도 호출
*/
	// A 와 Decorator 패턴의 차이는 ??
	// A : 필터 추가후에는 원본기능만 사용하고 싶다면
	//     다시 필터 제거해야 합니다.

	// Decorator : 언제라도 기능 추가 전의 객체에 접근 가능합니다.
	// ps : 기능추가전의 객체
	// e, f : 기능 추가후의 객체
}
