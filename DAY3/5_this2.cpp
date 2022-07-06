#include <iostream>

class Point
{
	int x, y;
public:
	// this 활용
	void set(int x, int y) 
	{
		// 1. 이름 충돌시, "멤버 접근을 명확히 하고싶을때"
//		x = x; // x 2개 모두 인자의 x
		this->x = x;
		this->y = y;
	}

	// 2. this 또는 *this 를 반환하는 함수
	//    => 멤버 함수를 연속으로 호출 가능합니다.
	Point* foo() { return this; }
	Point& goo() { return *this; } // 주의. 이 경우 Point 가 아닌
									//		Point& 로 해야 합니다.
};
int main()
{
	Point p1;
	p1.set(10, 20);

	p1.foo()->foo()->foo();
	p1.goo().goo().goo();

	// 아래 코드의 원리가 *this 반환 입니다. 
	std::cout << "A" << "B" << "C";
	// cout.operator<<("A").operator<<("B").operator<<("C")
}
