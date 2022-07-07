// 7_가상함수1  144 page ~
#include <iostream>

class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// function override : 기반 클래스 함수를 파생 클래스가 다시 만드는것
	// overloading 이 아닙니다. : square(int), square(double) 이 오버로딩
	void Cry1() { std::cout << "Dog Cry" << std::endl; }  // 2
};

int main()
{
	Animal a; a.Cry1(); // 1
	Dog    d; d.Cry1(); // 2

	Animal* p = &d;		// 객체는 "Dog", 포인터는 "Animal*"

	p->Cry1(); // 이 코드는 논리적으로는 "Dog Cry1" 를 호출해야 합니다.
			   // 객체가 Dog 이므로!! 
			   // C++, C# : Animal Cry1 호출
			   // java, swift, python, kotlin 등 대부분의 언어 : Dog Cry1
}

// 161 page
// p->Cry1() 을 어떤 함수로 연결할것인가 ? => "함수 바인딩" 이라고 합니다.