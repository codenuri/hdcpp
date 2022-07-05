// 5_생성자1.cpp
#include <iostream>
#include <string>

class Person
{
	std::string name;
	int  age;
public:
	/*
	void init(const std::string& n, // 사용자정의타입   : const &
		      int a)				// primitive type : call by value
	{
		name = n;
		age = a;
	}
	*/
	// 생성자(constructor)
	// 1. 클래스 이름과 동일한 이름의 멤버 함수
	// 2. 반환 타입을 표기하지 않고, 값을 반환할수 없다.
	// 3. 인자는 있어도 되고 없어도 된다.
	// 4. 객체를 생성하면 자동으로 호출된다.
	// 용도 : 멤버 데이타를 초기화 하기 위해
	Person(const std::string& n, int a)				
	{
		name = n;
		age = a;
	}
};

int main()
{
	// 모든 멤버 데이타가 public 에 있으면 아래처럼 초기화 가능합니다.
	// 하지만, 데이타가 private 에 있으면 에러 입니다.
//	Person p = { "kim", 28 };

//	Person p;
//	p.init("kim", 28);

	Person p("kim", 28); // 이 순간 자동으로 생성자가 호출됩니다.

}



