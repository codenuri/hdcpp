#include <iostream>

class Test
{
public:
	// 동일이름(인자도 동일)의 
	// "상수 멤버함수" 와 "비상수 멤버함수" 를 동시에 제공 가능합니다
	// => 많이 사용하지는 않고, 드물게 사용됩니다.
	void foo()       { std::cout << "foo" << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	Test t;		// 상수 객체 아님
	t.foo();	// "foo" 함수를 호출, 
				// "foo" 가 없다면 "foo const" 호출

	const Test ct;
	ct.foo();		// "foo const" 호출. 없다면 error
}

