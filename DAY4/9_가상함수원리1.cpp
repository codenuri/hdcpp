#include <iostream>

//가상함수 원리   164page ~

class Animal
{
	int age;
public: 
	virtual void Cry() {} // 1
	virtual void Run() {}
};

//--------------------
class Dog : public Animal
{
	int color;
public:	
	virtual void Cry() override {} // 2
};

int main()
{
	Animal a;
	Dog    d;
	Animal* p = &d;
	p->Cry();	// 2
				// Cry 가 가상함수 이므로 
				// 실행시간에 p가 가리키는곳을
				// 조사후 호출
}


