//  5_연산자재정의 - 182(131) page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }

	
	Point operator+(const Point& pt)
	{
		std::cout << "member operator+" << std::endl;
		Point temp(x + pt.x, y + pt.y);
		return temp;
	}	
	friend Point operator+(const Point& p1, const Point& p2);
};
// 멤버가 아닌 함수로 구현한 operator+
Point operator+(const Point& p1, const Point& p2)
{
	std::cout << "non-member operator+" << std::endl;
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;   // 1. p1.operator+(p2) 가 있으면 사용
						  // 2. operator+(p1, p2) 가 있으면 사용
						  // 둘다 없다면 컴파일 에러..

	p3.print(); // 3, 3

	// 멤버 함수가 좋을까요 ? 일반 함수로 만드는게 좋을까요 ?
	// 멤버를 좋아하는 개발자의 주장 : private 에 접근하려면 멤버 함수가 좋다.
	//							  객체지향에 충실하자.!!

	// 일반 함수를 좋아하는 개발자의 주장 : 멤버 함수로 만들수 없는 경우가 있다.
	
	int n = 3;
	Point p4 = p1 + p2; // p1.operator+(Point)
	Point p5 = p1 + n;  // p1.operator+(int)
	Point p6 = n  + p2; // n.operator+(Point) 가 있으면 되는데..
						// => n는 int 타입이므로 멤버함수를 만들수 없다.
						// => 결론, 이 경우는 "멤버 함수로 구현할수 없다."
						// => 일반함수로는 할수 있다.
						// operator+(int, Point)
}
// 연산자 재정의 정리(186 page)
// 1. 아래 4가지 연산자는 재정의 할수 없습니다.
//   => ::   .   .*   ?*

// 2. 아래 4개는 멤버 함수로만 해야 합니다.
//   => =, (), [], ->

// 3. 인자가 모두 primitive 타입일수는 없습니다.
// => 아래 코드에서 인자 a, b 중 한개 이상은 "사용자 정의 타입"이어야 합니다.
int operator+(int a, int b) // error. 이코드는 컴파일 안됨
{
	return a - b;
}

int n = 3 + 2;

// C++에서 "연산자 재정의를 사용한 기법"은 너무나 많습니다.
// => 중고급 과정 참고