#include <iostream>

// 앞의 코드를 컴파일러가 아래 처럼 변경합니다.
// 1. 모든 가상함수의 주소를 담는 배열을 전역적으로 생성합니다.
void* Animal_vtable[] = { RTTI정보, &Animal::Cry, &Animal::Run };


class Animal
{
	void* vtptr = Animal_vtable; // 컴파일러가 추가한 멤버
	int age;
public:
	virtual void Cry() {} // 1
	virtual void Run() {}
};
//Animal a1; // sizeof(a1) => sizeof(int) + sizeof(포인터)
//Animal a2;









//--------------------
// Dog가 한개만 override 해도 table에는 모든(Animal의) 가상함수 주소가 있습니다.
void* Dog_vtable[] = { RTTI정보, &Dog::Cry, &Animal::Run };

class Dog : public Animal
{
	void* vtptr = Dog_table;
	int color;
public:
	virtual void Cry() override {} // 2
};


int main()
{
	Animal a;
	Dog    d;
	Animal* p = &d;

	p->Cry(); // 이 한 줄의 원리

	// 1. 컴파일러는 p가 "Animal*"라는 것만 안다
	// 
	// 2. Cry() 가 가상인지 아닌지 조사해야 한다.
	//    => Animal 클래스를 보고 조사

	//    A. Cry 가 virtual 이 아니면
	//    => 포인터 타입인 Animal Cry 호출(static binding)
	//	  => call Animal::Cry()

	//    B. virtual 이면. 아래 의미의 기계어 코드 생성
	//    => p->vtptr[1]()
	//    => 위 코드가 실행되면, 결국 메모리에 보관중인
	//	     함수의 주소를 꺼내서 호출하게 됩니다.

	//	  => 1은 가상함수가 놓인 순서 입니다.
}
// 오버헤드
// 1. 가상함수 테이블 때문에 메모리 오버헤드
// 2. 객체당 한개씩 "vtptr" 멤버 추가
// 3. 호출시, 함수 주소를 꺼내서 호출하게 되므로(간접호출)
//    약간 느리다.








