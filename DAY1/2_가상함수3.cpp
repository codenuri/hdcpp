// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// #1. 가상함수 override 시에는 "virtual" 은 있어도 되고 없어도 됩니다
//	virtual void foo() {}
//	void foo() {}   // 이 코드도 위와 동일
					// 그런데, virtual 을 붙이는게 가독성이 좋습니다.

	// #2. 가상함수 OVERRIDE 시 실수(오타)가 있어도
	// => 에러가 아닙니다.
	// => 컴파일러는 다른 함수를 만든 것으로 생각
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. 위문제의 해결책으로 c++11 에서 override 키워드 도입

	virtual void fooo() override {}
	virtual void goo(double) override {}

};

int main()
{
}





