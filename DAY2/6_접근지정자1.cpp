// 4_접근지정자1 - 74page
#include <iostream>
#include <string>

// 프로그램에서 "사람"을 관리할 필요가 있었다.
// => "사람" 타입을 먼저 설계 하자.

struct Person
{
private:				// 이 아래 멤버는 멤버 함수만 접근가능
						// 멤버가 아닌 함수에서는 접근 안됨.
	std::string name;
	int  age;		

public:				// 이 아래 멤버는 모든 함수에서 접근 가능
	void setAge(int a)
	{
		// 인자 값의 유효성을 확인해서, 유효한 경우만 상태를 변경한다.
		// 객체가 항상 유효한 상태를 가질수 있도록 한다.
		if ( age > 0 && age < 150 )
			age = a;
	}
};
int main()
{
	Person p;

//	p.age = -10; // age 를 직접 접근하면
				 // 현실세계에 존재할수 없는 잘못된 객체(사람)이 생성
	p.setAge(-10);

				 
}
