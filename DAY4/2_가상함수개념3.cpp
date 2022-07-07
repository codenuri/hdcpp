// 7_가상함수1  144 page ~
#include <iostream>

class Animal
{
public:
	// non-virtual : 기본적으로 static binding 합니다.
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : 함수 호출시 dynamic binding 해달라는 것
	virtual void Cry2() { std::cout << "Animal Cry2" << std::endl; } 
};
class Dog : public Animal
{
public:
	        void Cry1() { std::cout << "Dog Cry1" << std::endl; } 
	virtual void Cry2() { std::cout << "Dog Cry2" << std::endl; }
};
int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d;

	p->Cry1(); // static binding, 무조건 포인터 타입으로 결정
	p->Cry2(); // dynamic binding, 실행시간에 p가 가리키는 곳이 어떤 객체인지 조사해서
				//                 호출을 결정
}


