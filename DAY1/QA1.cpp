// QA1.cpp
#include <iostream>

// class 와 struct 는 디폴트 접근지정자만 다르고 모든 것을 동일 합니다.
struct A { int a;};
struct B { int a;};

// 핵심 : 다중 상속
struct X : public A, public B
{
	int x;
};

int main()
{
	X x;
	A* pa = &x;
	A* pb = &x;

	printf("%p\n", &x);
	printf("%p\n", pa);
	printf("%p\n", pb);
}