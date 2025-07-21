#include <iostream>

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // 아무 문제 없음

	// 아래 코드도 아무 문제 없음
//	Derived* p = new Derived;
//	delete p;

	// 아래 코드는 버그
	Base* p = new Derived;
	delete p; // 이순간 소멸자 호출해야 합니다.

	// 소멸자 호출도 결국 함수호출 입니다.
	// p->소멸자() 가 됩니다.
	// #1. static binding 할지 dynamic 할지 결정해야 합니다.
	// #2. 

}	
