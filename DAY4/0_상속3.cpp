// 상속과 생성자.   135page ~
#include <iostream>
// 핵심 1. 파생 클래스 객체 생성시 기반 클래스 생성자도 호출된다.
//     2. 호출되는 순서 알아 두세요
//			=> 기반 클래스 생성자
//			=> 파생 클래스 생성자
//			=> 파생 클래스 소멸자
//			=> 기반 클래스 소멸자

// 3. 그런데, 위 순서보다는 정확한 원리를 알아야 합니다. 

class Base
{
	int base_member;
public:
	Base()      { std::cout << "Base()"  << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
	int derived_member;
public:
	// 사용자가 만든코드	// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base()	
	{
		std::cout << "Derived()" << std::endl; 
	} 
	Derived(int a)		// Derived(int a) : Base() //<== 핵심. 컴파일러가 추가한
	{								// 코드는 항상 기반 클래스의 디폴트 생성자호출												
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()      
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 사용자가 만든 코드가 모두 실행되고 나서
		// 제일 아래 부분에 컴파일러가 아래 코드 추가
		// ~Base();
	}
};

int main()
{
	Derived d;	
//	Derived d(5);
}




