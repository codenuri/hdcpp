// 4_인터페이스 - 171 page
#include <iostream>

// Camera, HDCamera, UHDCamera 객체에 take()를 사용할때, 
// override는 안붙여도 되는건가요?
// => 붙이는게 좋습니다.!!


// 강한 결합(tightly coupling)
// => useCamera(Camera* p)
// => 하나의 클래스가 다른 클래스 사용시 "클래스 이름"을 직접 사용하는것
// => 교체 불가능한 경직된 디자인

// 약한 결합(loosely coupling)
// => useCamera(ICamera* p)
// => 하나의 클래스가 다른 클래스 사용시 규칙을 담은 추상클래스를 통해서 사용하는것
// => 교체 가능한 유연한 디자인

// 일반적으로 아래처럼 이야기 합니다.
// 다른 언어는 "interface"라는 키워드가 있습니다.(C++은 없습니다.)
// 추상 클래스 : 지켜야 하는 규칙(순수 가상함수) + 다른 멤버도 있는 경우
// 인터페이스  : 지켜야 하는 규칙(순수 가상함수)만 있는 경우


// Camera 를 먼저 만들지 말고..
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 하지말고
//			=> 모든 카메라는 "take" 를 만들어야 한다는 의미.
// 
//       "모든 카메라는 ICamera 인터페이스를 구현해야 한다" 라고 표현하세요
class ICamera
{
public:
	virtual void take() = 0;
	virtual ~ICamera() {}  // 인터페이스는 결국 기반 클래스 입니다
							// 소멸자는 꼭 가상함수로 하세요..
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

