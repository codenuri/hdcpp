#include <iostream>

// 핵심 : 기반 클래스로 사용되는 모든 클래스는 
//	     반드시 소멸자를 "가상함수"로 해야 한다.
//		=> 기반 클래스 소멸자가 가상함수이면, 모든 파생 클래스의 소멸자도 가상함수가 됩니다

class Base
{
public:
	Base()  {  }
	virtual ~Base() {  }
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived()" << std::endl; }

	// 아래 소멸자 앞에 "virtual" 이 없지만
	// => 기반 클래스 소멸자가 virtual 이면 모든 파생 클래스 소멸자는 virtual 입니다.
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
//	Derived d;

//	Derived* p = new Derived;
//	delete p; 

	Base* p = new Derived;	// 1. 메모리 할당
							// 2. 생성자 호출

	delete p;	// 1. 소멸자 호출 ( 결국 소멸자라는 함수를 호출하는 것)
				//		static binding  : 포인터 타입으로 호출
				//		dynamic binding : p가 가리키는 객체가 어떤 객체인지
				//						 조사후 호출
				//	=> 이 순간 컴파일러는 소멸자가 가상인지 아닌지 조사해야 합니다.
				//  => 그런데, p 는 Base* 이므로 컴파일러는 Base 클래스를 조사하게됩니다.
				//  => 따라서, Base 의 소멸자에 virtual 을 표기해야 합니다.
				// 
				// 2. 메모리 해지
}