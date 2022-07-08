// 189page
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};
// 핵심 : 사용자 정의 타입의 객체를 std::cout 으로 출력되게 하려면
// => "operator<<" 함수를 일반 함수로 아래처럼 제공하면 됩니다.

// const Point& pt : 이함수 안에서 pt를 변경할 이유는 없습니다.
//                   그래서 안전하게 하려고 const를 붙입니다. (좋은 코드)
std::ostream& operator<<(std::ostream& os,  const Point& pt)
{
	os << pt.x << ", " << pt.y;
	return os;
}

int main()
{
	Point p(1, 2);

	std::cout << p ; // cout.operator<<(Point) 가 필요 하다.
					 // => cout 은 ostream 타입인데.. 우리가 만든 클래스가 아니다.
					 // => 멤버 함수를 추가할수는 없다.

					 // 멤버 함수가 안되면, 일반함수로 하면 된다.
					 // => operator<<(cout, p)
					 // => operator<<(ostream, Point) 를 만들면 된다.
					  
	// cout 와 참조
	// => 핵심 : cout을 참조(reference)로 받을때는 const 를 붙이면
	//          "operator<<" 를 사용할수 없습니다.
	std::ostream& os1 = std::cout;  // os1은 결국 cout의 별명입니다.

	os1 << "hello"; // ok..


	const std::ostream& os2 = std::cout;

	os2 << "hello"; // error..
					// os2.operator<<("hello") 의 원리 인데..
					// operator<<() 는 상수 멤버 함수가 아닙니다.
					// "상수객체(os2)는 상수 멤버 함수만 호출가능하다."

}


