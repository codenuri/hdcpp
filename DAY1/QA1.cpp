// QA1.cpp
#include <iostream>

// class 와 struct 는 디폴트 접근지정자만 다르고 모든 것을 동일 합니다.
struct A { int a;};
struct B { int b;};

// 핵심 : 다중 상속
struct X : public A, public B
{
	int x;
};

int main()
{
	X x;
	A* pa = &x;     // 1000
//	B* pb = &x;     // &x + sizeof(A) => 1004
//	B* pb = (B*)&x; // &x + sizeof(A) => 1004
//	B* pb = static_cast<B*>(&x); // &x + sizeof(A) => 1004

	// 핵심 
	B* pb = reinterpret_cast<B*>(&x); //??


	printf("%p\n", &x); // 1000
	printf("%p\n", pa); // &x와 동일.  
	printf("%p\n", pb); // 캐스팅 방법에 따라 달라짐. 위 캐스팅 코드 참고
}