#include <iostream>
#include <cstring>

// shallow copy vs deep copy

// shallow copy
// => 디폴트 복사 생성자가 메모리 자체를 복사하는 것이 아니라
//    주소만 복사하는 현상
// => 해결책 : 사용자가 복사 생성자를 만들어야 한다.

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age{c.age}
	{
		// #1. 포인터가 아닌 멤버는 그냥 복사
		// age = c.age; 여기서 하지말고, 초기화 리스트에서
		//			

		// #2. 포인터 멤버는 메모리 할당후
		//     메모리 자체를 복사
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name)+1, c.name);
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1; 
}
