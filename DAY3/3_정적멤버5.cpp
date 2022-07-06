// 정적멤버5,  4번 복사해오세요.
#include <iostream>
// Car.h
class Car
{
	int color;
	static int cnt;
public:
	Car();
	~Car();

	static int getCount();
};

// Car.cpp
#include "Car.h"

int Car::cnt = 0; // 핵심 1. static 멤버변수의 외부 선언은 .cpp에 놓게됩니다.

Car::Car() { ++cnt; }
Car::~Car() { --cnt; }

// 핵심 2. static member function 를 클래스외부에서 구현부를 작성할때는
//        "static" 을 표기하면 안됩니다.
int Car::getCount() 
{
	return cnt; 
}



int main()
{
	std::cout << Car::getCount() << std::endl;
}

