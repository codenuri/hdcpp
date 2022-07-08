#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체의 특징
int main()
{	
	Point pt(1, 2);
	
	pt.x = 10;			// ok	
	Point(1, 2).x = 10;	// error. 임시객체는 등호의 왼쪽에 놓일수 없습니다.
						

	Point* p1 = &pt;			// ok		
	Point* p2 = &Point(1, 2);	// error. 임시객체는 주소 연산자로 
								//		  주소를 구할수 없습니다.
							

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. 임시객체는 reference로 가리킬수
								//		  없습니다.

	// 상수 참조는 임시객체를 가리킬수 있습니다.
	// => 이 경우, 임시객체의 수명의 "참조의 수명"으로 연장 됩니다.
	// => 이름없는 객체에 이름을 부여 한것
	const Point& r3 = Point(1, 2); // ok


}





