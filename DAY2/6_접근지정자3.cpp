#include <iostream>
#include <string>

// 아래 코드는 C++ 언어의 코딩 스타일 입니다.
class Person
{
private:				
	std::string name;
	int  age;
public:
	void setAge(int a)
	{
		if (age > 0 && age < 150)
			age = a;
	}
};
// 아래 코드는 C++을 제외한 대부분의 객체지향 언어 스타일 입니다.
// C#, java, swift 등
class Person
{
	// 모든 멤버 앞에 각각 접근 지정자 표기
	private std::string name;
	private int  age;
	
	public void setAge(int a)
	{
		if (age > 0 && age < 150)
			age = a;
	}
};
// 참고 : 대부분의 객체지향 언어는 접근지정자가 있는데
//       python 에는 접근지정자가 없습니다.

// private 에도 함수를 만들수 있나요? 있다면 어떤 예에서 사용할 일이 있을까요
// => 네 만들어도 됩니다.
// => 그냥, 클래스 내부적으로만 사용하려고 만듭니다.

class Machine
{
private:

	// 1. 다양한 멤버함수가 사용하는 공통의 작업인데..
	// 2. 이 작업만 별도로 수행할수는 없다(즉, 외부에서 호출하지 못하게)
	// => private 에 만드세요.
	void common_work() {}

public:
	void start()
	{
		//...
		common_work();
		//...
	}
	void go()
	{
		common_work();
	}
};