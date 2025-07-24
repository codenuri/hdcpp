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
	}

	// temporary(rvalue) 전용 복사 생성자
	Cat(Cat&& c) : age{c.age}, name{c.name}
	{	
		// 임시객체가 파괴될때
		// 자원삭제를 막기 위해 
		// 자원 포인터 reset
		c.name = nullptr;

		// 위 코드를 수행하려면
		// 임시객체도 "상수성" 없이 참조할수 있어야 합니다.
		// 그래서 아래 문법을 만든것 
		// Point&& r = Point{1,1}
	}
};

Cat foo()
{
	Cat c{"yaong", 3};
	return c;	// 임시객체반환
}

int main()
{
	Cat c1{"nabi", 2};

	Cat c2 = c1; 
	Cat c3 = foo();  // 이순간의 메모리 그림 생각하세요
					 // 단점 생각해 보세요
}
