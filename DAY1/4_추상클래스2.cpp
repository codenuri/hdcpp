//1_추상클래스2.cpp
#include <iostream>

// 아래 코드는 "OCP" 를 만족할수 없습니다.
// => 새로운 카메라 추가시
// => People 클래스는 수정되어야 합니다

// => 해결은 다음소스

class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:	
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);	
}





