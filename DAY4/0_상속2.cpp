// 상속2
// 핵심 
// C++ 의 접근지정자는 3개 입니다
// => private, protected, public

// 다른 객체지향 언어에는 "대부분 3개를 지원하고", 
// 추가로 1~2개정도 더 지원하기도 합니다.( internal, package 등)

class Base
{
private:   int a;	// 멤버 함수만 접근 가능
protected: int b;	// 멤버 함수만 접근 가능 + 파생 클래스 멤버함수가 접근가능
public:    int c;	// 모든 곳에서 접근 가능
};
class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;  // error. 기반 클래스 private 은 파생 클래스가 물려는 받지만
				//	 	  접근할수는 없다.
				//		  접근하고 싶다면 기반 클래스의 멤버 함수 사용.
		b = 0;  // ok
		c = 0;  // ok
	}
};
int main()
{
	Base base;
	base.a = 0; // error
	base.b = 0; // error. protected 는 멤버가 아닌 곳에서는 접근 안됨
	base.c = 0; // ok
}
