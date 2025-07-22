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
									// "이미 생성된 객체"를 가리키겠다는 것
public:	
	Emoticon(PhotoSticker* o) : origin(o) {}

	void draw()
	{
		std::cout << "####################\n";	
		origin->draw();					
		std::cout << "####################\n";
	}
};

class Frame 
{
	PhotoSticker* origin = nullptr; 
public:	
	Frame(PhotoSticker* o) : origin(o) {}
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

	Emoticon e(&ps); // 이미 존재하는 객체(ps)에 기능을 추가하겠다는것
	e.draw();	

	Frame f(&ps);
	f.draw();		
}

