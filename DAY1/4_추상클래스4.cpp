#include <iostream>

//----------------------------------------------------
// 인터페이스 : 지켜야 하는 규칙만 있는 경우
// 추상클래스 : 지켜야 하는 규칙 + 다른 멤버

// java, C# 은 "interface", "abstract" 를 키워드존재
// C++ 은 위와 같이 의미로만 구문
//---------------------------------------
// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용
// => 교체 불가능한 경직된 디자인
// => People::use_camera(HDCamera*)

// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 규칙(인터페이스)를 통해서 사용하는것
// => 교체 가능한 유연한 디자인
// => People::use_camera(ICamera*)
//-------------------------------
// SOLID : 객체지향 프로그램이 지켜야하는 5개 규칙
// SRP
// OCP -> 배운 내용
// LSP
// ISP
// DIP : 구체(concrete)에 의존하지 말고 추상에 의존해라
// => 의존관계 역전(Dependency Inversion Principle)
// => HDCamera 가 필요하지만
// => 사용할때는 ICamera* 를 사용하라는 것
//-----------------------------------

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.
class ICamera 
{
public:
	virtual void take() = 0;
};

class People 
{
public: 
	void use_camera(ICamera* c) { c->take();}
};

class Camera : public ICamera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera: public ICamera
{
public:	
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera: public ICamera
{
public:	
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);	

	UHDCamera uhc;
	p.use_camera(&uhc);
}





