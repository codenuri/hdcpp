#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가 : 클래스에 기능을 추가한것
// 포함을 사용한 기능의 추가 : 객체에 기능을 추가할수 있다.
class Emoticon 
{
	PhotoSticker* origin = nullptr; // 핵심 : 포인터 또는 참조 멤버로
									//        값 타입 아님.
public:	
	Emoticon(PhotoSticker* o) : origin(o) {}


	
	void draw()
	{
		std::cout << "####################\n";	
		PhotoSticker::draw();					
		std::cout << "####################\n";
	}
};



class Frame : public PhotoSticker
{
public:	
	void draw()
	{
		std::cout << "--------------------\n";	
		PhotoSticker::draw();					
		std::cout << "--------------------\n";
	}
};
int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon e;
	e.take();	
	e.draw();	

	Frame f;
	f.take();	
	f.draw();		
}

