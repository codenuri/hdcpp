// 6_함수1.cpp  28 page ~
// C++함수의 특징 1. 디폴트 파라미터

// 핵심 : 인자를 전달하지 않은 경우, 디폴트로 지정된 값 사용

// 주의 사항
// 1. 함수를 선언과 구현으로 분리할때, 디폴트 값은 선언에만 표기해야 합니다.
// 2. 반드시 마지막 인자부터 차례대로만 지정해야 합니다.

void f1(int a = 0, int b = 0, int c)     {} // error
void f2(int a = 0, int b ,    int c = 0) {} // error
void f2(int a    , int b = 0, int c = 0) {} // ok


void foo(int a = 0, int b = 0, int c = 0);

int main()
{
	foo(1, 2, 3);
	foo(1, 2);		// foo(1,2,0)
	foo(1);			// foo(1,0,0)
	foo();			// foo(0,0,0)
}

void foo(int a /* = 0 */, int b /* = 0 */, int c /* = 0*/)
{
}

