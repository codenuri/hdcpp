#include <iostream>

class Animal
{
public:
	// non-virtual : 기본 정책인 static binding 하라는 의미
	//				 컴파일 시간에 포인터 타입으로 결정
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual : dynamic binding 하라는 의미
	//			 실행시간에 메모리 조사해서 함수 결정
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry1(); // 1. 클래스 선언을 보고 가상함수인지 아닌지 조사
				// 2. 가상이 아니므로 포인터 타입으로 호출 결정
				// Animal cry1
				
	p->cry2(); 	// 가상이므로dynamic binding
				// Dog cry2 호출
}


