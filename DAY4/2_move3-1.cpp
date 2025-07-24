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

	Cat c2 = c1; 	 	// copy
	Cat c3 = foo();  	// move

	Cat c4 = static_cast<Cat&&>(c2);  // move
	Cat c5 = std::move(c3);  		  // move
}

// 대부분의 C++ 컴파일러는 최적화를 합니다.
// 그래서 위 코드 컴파일시에는 결과가 예상과 다릅니다.

// C++ 학습시 "다양한 최적화를 제거하고" 실행해 보세요

// g++ 소스이름.cpp -fno-elide-constructors 


// -fno-elide-constructors : 생성자(복사, 이동) 를 제거하는 최적화를
//							 하지 말라 