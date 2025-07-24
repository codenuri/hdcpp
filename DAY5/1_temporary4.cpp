#include <iostream>

class Point
{	
public:
	int x, y;
	Point(int a, int b) x:{a}, y{b} {}	
};

int main()
{
	Point pt(1, 1);

	// #1. 임시객체 특징
	pt.x = 10;				// ok
	Point{1, 1}.x = 10;		// error. 등호의 왼쪽에 올수 없다.

	// 특징 #2
	Point* p1 = &pt;		// ok
	Point* p2 = &Point{1,1};// error. 임시객체를 주소를 구할수 없다.

	// 특징 #3.reference 규칙

	Point& r1 = pt;			// ok
	Point& r2 = Point{1,1};	// error. 임시객체를 레퍼런스로	
							//        가리킬수 없다.


	const Point& r3 = Point{1, 1}; // ok.. 핵심
						// 임시객체를 const reference로 
						// 가리킬수 있다.
						// => 이렇게 만든 이유는 temporary 2, 3번처럼
						//    함수 인자로 사용할때를 위해서
						// 이 경우 임시객체의 수명은 "r3의 수명"으로
						// 연장됩니다.(lifetime extension)

	// C++11 만들때 임시객체를 const 속성없이 가리킬 필요가 있었습니다.
	// => move 를 위해서
	// => 그래서 새로운 reference 문법 도입
	// => "rvalue reference" 라는 문법
	Point&& r4 = Point{1,1}; // ok..
							 // 역시 수명 연장됨.




	// #2. 용어
	// lvalue : 등호의 왼쪽에 올수 있는 표현식
	//			이름이 있다.
	// rvalue : 등호의 왼쪽에 올수 없는 표현식
	//			이름이 없다.
	int n = 3;
	n = 20;
	3 = 20;

	// 
}







