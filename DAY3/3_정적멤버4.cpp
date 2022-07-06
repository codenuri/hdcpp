#include <iostream>

class Car
{
	int color;
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }

//	int getCount() { return cnt; }	// non-static 멤버 함수
									// => 반드시 객체가 있어야 호출 가능.

	static int getCount() { return cnt; }	// static 멤버 함수
											// 객체가 없어도 호출 가능
};

int Car::cnt = 0; // private 에 있어도 여기서 초기화는 가능합니다.


int main()
{
	std::cout << Car::getCount() << std::endl;

	Car c1;
	Car c2;

	std::cout << Car::getCount() << std::endl;	// <== 이렇게 사용 하세요
	std::cout << c1.getCount() << std::endl;	// <== 이렇게 하지 말고
}
// static member data(정적 멤버 데이타)
// => 객체가 없어도 메모리에 놓이고
// => 모든 객체가 공유
// => 접근 지정자를 사용할수 있는 전역변수
// => "객체 멤버" 가 아닌 "클래스 멤버" 라고 표현 합니다.

// static member function(정적 멤버 함수)
// => 객체 없이 호출 가능한 멤버 함수
