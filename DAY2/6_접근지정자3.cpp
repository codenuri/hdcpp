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