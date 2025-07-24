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

	Cat(Cat&& c) : age{c.age}, name{c.name}
	{	
		c.name = nullptr;
	}
};

Cat foo()
{
	Cat c{"yaong", 3};
	return c;	
}

int main()
{
	Cat c1{"nabi", 2};

	Cat c2 = c1; 	// c1 은 lvalue. 복사 생성자 호출
	Cat c3 = foo(); // 우변은 임시객체(rvalue). 이동(move) 생성자 호출

	Cat c4 = static_cast<Cat&&>(c2); // 이동 생성자 호출
	Cat c5 = std::move(c3); // 이 함수가 위와 같은 캐스팅을 합니다.
}

// std::move 가 실제 자원이동하는 것 아닙니다.
// => std::move 는 단지 rvalue  캐스팅 할뿐입니다.
// => 캐스팅 결과로 해당 클래스의 "복사 생성자" 아닌 "이동 생성자" 가
//    호출됩니다.

// std::move 라는 함수 이름에 비판이 많습니다.
// => 특히 "C++ 창시자"가 비판