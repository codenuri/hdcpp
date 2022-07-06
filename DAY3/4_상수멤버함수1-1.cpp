#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 상수 멤버 함수(const member function)
	// => 멤버 함수 () 뒤에 "const" 를 붙이는 문법
	// => 멤버 함수 안에서는 "멤버데이타를 수정하지 않는다"고 컴파일러에게 알려주는것
	
	// => "상수객체"라도 "상수 멤버 함수"는 호출가능하다
	void print() const
	{
//		x = 100;	// error. 상수 멤버 함수에서는
					//		  멤버 데이타를 수정할수 없다.

		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point p(1, 2);

	p.x = 10;		// error. 
	p.set(10, 20);	// error. 
	p.print();		// ok.. 상수 객체라도 print 는 상수 멤버 함수이므로
					// 호출가능하다.
}




