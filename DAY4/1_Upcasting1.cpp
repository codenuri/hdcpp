// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:	
	int age;
};
class Dog : public Animal
{
public:	
	int color;
};
int main()
{
	Dog     dog;

	Dog*    p1 = &dog; // ok
	int*    p2 = &dog; // error
	Animal* p3 = &dog; // ok. upcasting
					 
	// 핵심 1. 기반 클래스 포인터로     파생 클래스 객체의 주소를 담을수 있다.
	//        기반 클래스 reference로 파생 클래스 객체를 가리킬수도 있다.
	//		=> upcasting 이라고 합니다.

	// 핵심 2. 기반 클래스 포인터로 파생 클래스 객체를 가리킬수 있지만
	//        이 경우, 기반 클래스의 멤버만 접근 가능하고
	//		  파생 클래스가 추가한 멤버는 접근할수 없다.
	//		  "접근 가능 여부를 컴파일 시간에 포인터 타입으로만 확인 하므로"
	p3->age = 10; // ok
//	p3->color = 20; // error

	// 핵심 3. 파생 클래스 고유의 멤버에도 접근하려면 
	//        "파생 클래스 타입으로 캐스팅하면 됩니다."
	//		  단, p3가 가리키는 것이 "Dog"라는 확신이 있을때만..
	static_cast<Dog*>(p3)->color = 20; // ok
}




