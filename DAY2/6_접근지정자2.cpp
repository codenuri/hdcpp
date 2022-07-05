#include <iostream>
#include <string>


// C++에서 class 와 struct 의 차이점은 오직 한가지 입니다.

// struct : 접근지정자 생략시 디폴트가 public
// class  : 접근지정자 생략시 디폴트가 private


// 단, C#, java, swift 등의 대부분의 다른 언어는 아주 큰차이가 있습니다.
// struct : value type
// class  : reference type

// class 사용하는 이유는 그럼 struct보다 
// 명시적으로 private 기능을 사용하기위해서 사용하는 걸까요?
// ==> 네 맞습니다..


//struct Person
class Person
{
//private:				
	std::string name;
	int  age;

public:				
	void setAge(int a)
	{
		if (age > 0 && age < 150)
			age = a;
	}
};



int main()
{
	Person p;
	p.setAge(-10);


}
