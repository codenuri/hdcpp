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
	// static_cast<B*>(&x) : &x 에서 B 의 모양을 찾아라
	//						 반환 값은 &x 가 아닌 B의 모양이 있는 주소
	//						 B가 없다면 관련성 없으므로 에러

	// reinterpret_cast<B*>(&x) : &x 주소를 무조건 B타입으로 해석하겠다는 의도
	//							 연관성 없어도 됩니다.
	//							 항상 &x 주소 반환.
	B* pb = reinterpret_cast<B*>(&x); // 1000

	pb->b = 10; // x 객체의 어느 멤버가 변경될까요 ?
				// x.a 에 10 대입!

	printf("%p\n", &x); // 1000
	printf("%p\n", pa); // &x와 동일.  
	printf("%p\n", pb); // 캐스팅 방법에 따라 달라짐. 위 캐스팅 코드 참고
}