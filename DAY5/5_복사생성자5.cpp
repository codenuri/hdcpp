#include <iostream>
#include <cstring>
#include <string>

// 클래스 내부에 포인터 멤버가 없고, 동적 메모리 할당을 하지 않는다면..
// 컴파일러가 제공하는 복사 생성자를 사용해도 안전합니다.

// char* 를 사용하지 말고 string 을 사용했다면 "얕은 복사" 같은 문제는 없습니다.


class Person
{
//	char* name;			// 문자열이 필요하면 이렇게 하지말고
	std::string name;	// std::string 사용하세요.
	int   age;
public:
	Person(const std::string& s, int a) : name(s), age(a)
	{
	}
};

int main()
{
	Person p1("kim", 25);
	Person p2 = p1;


}