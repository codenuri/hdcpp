#include <iostream>
#include <cstring>

// 클래스 내부에 포인터 멤버가 있고, 동적 메모리 할당을 사용하면
// 컴파일러가 제공하는 복사 생성자는 "얕은 복사(shallow copy)" 현상이 있습니다.

// 사용자가 복사 생성자를 제공해서 해결해야 합니다.

class Person
{
	char* name;
	int   age;
public:
	Person(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}
	~Person() { delete[] name; }

	// 깊은 복사(Deep copy)로 구현한 복사 생성자
	Person(const Person& p) : age(p.age)
	{
		// 1. 포인터가 아닌 멤버는 그냥 복사
		//age = p.age;	// 복사 생성자도 생성자 입니다.
						// 이렇게 하지 말고
						// 초기화리스트 사용하세요.


		// 2. 포인터 멤버는 메모리 할당후
		//    메모리 자체를 복사 

		name = new char[strlen(p.name) + 1];
		
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}
};


int main()
{
	Person p1("kim", 25);
	Person p2 = p1;


}