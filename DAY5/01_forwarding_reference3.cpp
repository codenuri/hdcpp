// 함수 인자와 reference 규칙
void f1(int&  r) {}
void f2(int&& r) {}

int n = 3;
f1(n); // ok
f1(3); // error

f2(n); // error
f2(3); // ok

// 함수 인자로
// int&	 : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.

template<typename T> void f3(T& a)
{
}

template<typename T> void f4(T&& a)
{
}
