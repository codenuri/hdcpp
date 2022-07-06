#include <iostream>

// 방법 3. static member data 사용

//int cnt = 0; // 전역변수는 접근지정자를 사용할수 없다.

class Car
{
	int color;
public:
//	int cnt = 0; // 이렇게 하면 "객체당 한개씩 생성" 됩니다.

	static int cnt; // static 멤버 데이타는 반드시 클래스 외부에도 선언해야 합니다.

	Car() { ++cnt; }
	~Car() { --cnt; }
};
// static 멤버 데이타는 반드시 외부 선언이 필요하고, 초기화도 여기서 해야 합니다
int Car::cnt = 0;

// static 멤버 데이타 특징
// 1. 객체를 한개도 만들지 않아도 "메모리에 존재" 합니다. 
//    => 위 외부 선언이 결국 전역변수를 만드는 의미와 유사 합니다.

// 2. 객체 생성시는 "non-static" 멤버만 따로 놓이게 됩니다.(color)
//    => cnt 는 객체 각각의 메모리에는 없습니다.
//    => static 멤버 데이타는 객체의 크기에 포함 안됨

int main()
{
	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl; // 2. 
}

