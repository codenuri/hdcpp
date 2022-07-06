// 6_초기화리스트1    85page ~
#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	// 멤버 초기화 리스트(member initializer list)
	// => 생성자() 뒤에 : 을 적고 멤버 데이타를 초기화 하는 기술
	Person(const std::string& n, int a) : name(n), age(a) // 좋은코드
	{
		// 아래 처럼 생성자 {} 안에서 멤버 데이타에 넣는것은 "좋은코드가 아닙니다"
		// name = n;
		// age = a;
	}
};



int main()
{
	Person p1("kim", 10);
}




