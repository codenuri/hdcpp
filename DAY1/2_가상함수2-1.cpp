#include <iostream>

// 결국 문제는
// #1. Base* p = new Derived; delete p; 코드가 있고
// #2. Derived 소멸자에 어떤 코드가 있을때만 문제가 됩니다.
// => 위 상황이 아니면 문제 없음. 


class Base
{
public:

	// protected 소멸자
	// Base* p 인 상태로 delete p 를 못하게 하는 기술
protected:
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
	Base* p = new Derived;
//	delete p; // 컴파일 에러. protected 소멸자 의도는	
			  // Base* 상태로는 delete 하지 말라는 것

	delete static_cast<Derived*>(p); // ok  

}	
