class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요 => 시험에 나옵니다. 꼭 기억해 두세요
	// => 핵심은  "static 멤버의 특징" 을 알면 됩니다.
	// static member function : 객체없이 호출가능
	// static member data     : 객체가 없어도 메모리에 존재
	void foo()	
	{
		color = 0;	// 1.
		cnt = 0;	// 2.
		goo();		// 3
	}
	static void goo()	
	{
		color = 0;	// 4. 
		cnt = 0;	// 5. 
		foo();		// 6. 
	}
};
int Car::cnt;

int main()
{
}
