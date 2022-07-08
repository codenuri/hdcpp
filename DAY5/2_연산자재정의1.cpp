//  5_연산자재정의 - 182(131) page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}
};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	// 다음중 어떤 코드가 보기 좋을 까요 ?
	Point p3 = Add(p1, p2); // C 언어 스타일

	Point p4 = p1.Add(p2);	// 객체지향 스타일, java 에서 널리 사용

	Point p5 = p1 + p2;     // C++ 창시자가 연산자를 "단축표기의 미학" 이라고 
							// 이야기 하면서.. 아주 좋아합니다... 

	// a + b 라는 코드가 있을때
	// 1. a, b가 모두 primitive 타입이면 : 그냥 덧셈 수행
	// 
	// 2. a, b중 한개라도 사용자 정의 타입이 있으면 아래 처럼 동작

	//    a.operator+(b) 를 찾고 있으면 호출, 없으면
	//    operator+(a, b) 를 찾고 있으면 호출.
	//    둘다 없으면 에러

}

