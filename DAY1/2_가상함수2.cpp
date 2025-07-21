#include <iostream>

// 핵심 : 반드시 알아야 하는 중요 문법
// => 업무에서 상속문법을 사용한다면
// => 기반 클래스의 소멸자는 "반드시 가상함수"로 작성해야 합니다.
// => 단, 이경우 아주 약간의 오버헤드
//    (가상함수테이블, 실행시간 호출에따른 성능 지연(mov 3회))
// => 단, 성능을 고려한다면 다른 기술(protected 소멸자)도 있습니다

class Base
{
public:
	virtual ~Base() {}
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
	// #2. 컴파일러는 p가 Base* 라는 것만 알고 있으므로
	//     Base 클래스에서 소멸자가 가상인지만 조사
	//	   (Derived 조사가 아님)
	// 가상이 아니면 : static binding, ~Base() 호출
	// 가상이 면     : dynamic binding, ~Derived() 호출

}	
