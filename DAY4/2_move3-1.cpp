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

	Cat(Cat&& c) : age{c.age}, name{c.name}
	{	
		c.name = nullptr;
		std::cout << "move\n";
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

	Cat c2 = c1; 	 
	Cat c3 = foo();  

	Cat c4 = static_cast<Cat&&>(c2);  
	Cat c5 = std::move(c3);  
}
