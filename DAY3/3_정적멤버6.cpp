class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요 => 시험에 나옵니다. 꼭 기억해 두세요
	// => 핵심은  "static 멤버의 특징" 을 알면 됩니다.
	// static member function : 객체없이 호출가능
	// static member data     : 객체가 없어도 메모리에 존재
	// 
	// 핵심 : static 멤버 함수에서는 "static 멤버(데이타,함수)"만 접근가능합니다.

	void foo()	
	{
		// 이 함수를 호출했다는것은 객체가 있다는 의미 입니다.
		color = 0;	// 1. ok
		cnt = 0;	// 2. ok
		goo();		// 3. ok
	}
	static void goo()	
	{
		color = 0;	// 4. error
		cnt = 0;	// 5. ok
		foo();		// 6. error
	}
};
int Car::cnt;

int main()
{
	Car::goo(); // static 멤버 함수 이므로
				// 객체 없이 호출가능
	Car c;
	c.foo(); // foo는 객체가 있어야 호출가능
}
