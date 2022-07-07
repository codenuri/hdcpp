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
	void Cry1() { std::cout << "Dog Cry" << std::endl; }  // 2
};

int main()
{
	Animal a; 
	Dog    d; 

	Animal* p = &d;		

//	if (사용자 입력 == 1) p = &a;

	// 컴파일 시간에는 p가 어떤 객체를 가리키는 지 알수 없다.
	p->Cry1(); 
}

// 161 page
// p->Cry1() 을 어떤 함수로 연결할것인가 ? => "함수 바인딩" 이라고 합니다.

// 1. static binding : 컴파일 시간에 컴파일러가 함수 호출을 결정하는 것
//					   컴파일 시간에는 p가 어떤 객체를 가리키는 지 알수 없다.
//					   컴파일러가 아는 것은 p 가 "Animal*" 라는 사실만 알수있다
//					   그래서 컴파일러가 함수 호출을 결정하면 
//					   무조건 포인터 타입으로 결정.. 
//					   Animal Cry1 호출
// early binding, 속도가 빠르다. 논리적으로는 맞지 않다.
// C++, C#
// 
// 2. dynamic binding : 컴파일 할때 p가 가리키는 곳을 조사하는 기계어 코드생성
//					실행할때 p가 가리키는 곳을 조사한후에
//					결과에 따라 함수 호출
//					p가 가리키는 곳에 Dog 가 있었다면 
//					Dog Cry1 호출
// late binding, 느리다.  논리적으로 맞다.
// java, swift, python, kotlin
// C++, C# 의 "가상함수" 라는 개념이 "dynamic binding" 해달라는 요청
 
// 반대로 자바나 파이썬도 스태틱 바인딩으로 요청할 수 있나요?
// => 안됩니다.


