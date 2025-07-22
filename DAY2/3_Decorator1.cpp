#include <iostream>

// PhotoSticker : 스티커 사진기 라고 생각해 보세요

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:	
	void draw()
	{
		std::cout << "####################\n";	// 추가된 기능
		PhotoSticker::draw();					// 원래의 기능
		std::cout << "####################\n";
	}
};
class Frame : public PhotoSticker
{
public:	
	void draw()
	{
		std::cout << "--------------------\n";	// 추가된 기능
		PhotoSticker::draw();					// 원래의 기능
		std::cout << "--------------------\n";
	}
};
int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 사진 출력(인화)

	Emoticon e;
	e.take();	
	e.draw();	

	Frame f;
	f.take();	
	f.draw();		
}

// 위 코드의 단점
// 1. 촬영된 사진객체(ps)에 기능 추가가 아니라
//    기능이 추가된 클래스를 사용해서 다시 사진을 촬영한다.
//    상속 : 클래스에 기능 추가!!
//	  원하는 것 : 객체에 기능..

// 2. 중첩된 기능 추가가 어렵다.(다중상속을 다시해야하고 복잡해진다.)
// => Emoticon 과 Frame 을 모두 추가 하고 싶다.

// 해결책 
// 위 코드 에서 "emoticon : PhotoSticker 기능 + 추가 기능"
// 이렇게 하지 말고
// => 추가 기능만 가지는 클래스를 만들자
// => 다음소스에서.. 