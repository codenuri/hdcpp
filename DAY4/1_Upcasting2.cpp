// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:	int age;
};
class Dog : public Animal
{
public:	int color;
};
class Cat : public Animal
{
public:	int speed;
};


int main()
{
	// Upcasting 활용/장점
	std::vector<Dog*> v1;	// Dog 객체 만 보관하는 vector

	std::vector<Animal*> v2;// 동종(동일부모로 부터 파생된 타입)을 저장하는 vector
							// 모든 동물의 객체를 저장할수 있다.	
}

//void NewYear(Dog* p)	// Dog 타입의 객체만 받을수 있는 함수
void NewYear(Animal* p)	// 모든 동물의 객체를 받을수 있는 함수
{						// 동종을 처리하는 함수를 만들수 있다.

	// 모든 동물은 새해가 되면 한살이 증가한다.
	++(p->age);

	// 단, 이 함수안에서는 "모든 동물의 공통의 특징, Animal 멤버" 
	// 만 사용해야 한다.
//	p->color = 10; // error. Animal 멤버가 아니다.
}

