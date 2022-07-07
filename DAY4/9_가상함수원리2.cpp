#include <iostream>

class A
{
	int a;
public:
	void foo() { std::cout << "foo" << std::endl; } // 1
};
class B   // 주의 상속관계 아닙니다.
{
	int b;
public:
	virtual void goo() { std::cout << "goo" << std::endl; } // 2
};

int main()
{
	A aaa;
//	B* p = &aaa; // error

	B* p = reinterpret_cast<B*>(&aaa); // ok.. 실전에서는 절대 이렇게 하면 안됩니다.
									// 가상함수 원리 설명을 위한 코드..(학습용)
	p->goo();  // 가상이면 p->vtptr[1]() 의미의 기계어 코드 생성
}

// foo 비가상, goo 비가상 : goo
// foo   가상, goo  가상 : foo
// foo   가상, goo 비가상 : goo
// foo 비가상, goo  가상 : runtime error
