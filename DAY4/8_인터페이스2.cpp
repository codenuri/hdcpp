// 4_인터페이스 - 171 page
#include <iostream>



// Camera 를 먼저 만들지 말고..
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다.
//			=> 모든 카메라는 "take" 를 만들어야 한다는 의미.
class ICamera
{
public:
	virtual void take() = 0;
};

// 실제 카메라는 없어도, 규칙이 있습니다.
// 카메라 사용자는 규칙 대로 사용하면 됩니다.
class Person
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

// 이제 모든 카메라는 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};
class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};
int main()
{
	Person p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);

	HDCamera uhc;		// 나중에 추가된 카메라지만.
	p.useCamera(&uhc);  // person 이 코드 수정없이 사용가능하다.
}

