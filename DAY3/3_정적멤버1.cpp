// 3_정적멤버1 - 110 page
#include <iostream>

// Car 타입의 객체를 몇개나 생성했는지 알고 싶다.!
// 방법 1. 멤버 데이타 cnt 사용
//    => 멤버 데이타는 "객체 별로 따로 메모리가 할당된다."
//    => 아래 코드에서 c1, c2 는 각각 자신만의 cnt를 가지게 된다.
//    => 생성된 객체의 갯수 파악 실패

class Car
{
	int color;
public:
	int cnt = 0;

	Car()  { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl; // 2를 기대하지만 결과는 1
}

