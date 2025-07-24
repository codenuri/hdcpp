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

	Cat(const Cat& c) : age{c.age}
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name)+1, c.name);
		std::cout << "copy\n";
	}
/*
	Cat(Cat&& c) : age{c.age}, name{c.name}
	{	
		c.name = nullptr;
		std::cout << "move\n";
	}
*/
};

int main()
{
	Cat c1{"nabi", 2};

	Cat c2 = c1; 	 		
	Cat c3 = std::move(c2); 

	// 핵심 : std::move() 를 사용하면
	// #1. move 생성자가 있는 타입은 "move 생성자 호출"
	// #2. move 생성자가 없는 타입은 "복사 생성자 호출"

	// 즉, move 생성자가 없는 class 도 std::move 사용가능
	// => 단, move 이 효과는 없고, 복사생성자 사용

	// class 설계자가 move 생성자를 만들지 않아도
	// 사용자는 std::move 사용할수 있다는것
}
