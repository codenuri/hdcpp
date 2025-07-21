#include <iostream>


// 카메라를 무조건 만들지 말고
// 카메라 제작자가 지켜야 하는 규칙을 만들자

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다.
class ICamera 
{
public:
	virtual void take() = 0;
};

// 이제 모든 사용자는 규칙대로만 사용해야 합니다.
// 실제 카메라가 없어도 "규칙"이 있으므로 코드 작성 가능합니다.
class People 
{
public: 
	// 추상클래스 라도 포인터 변수는 사용가능
	void use_camera(ICamera* c) { c->take();}
};

// 모든 카메라는 규칙을 지켜야 한다.
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
	p.use_camera(&uhc);	// OCP 만족!!
}





