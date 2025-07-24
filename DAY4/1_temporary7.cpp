#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) x:(a), y(b){}	
};

void foo(Point& pt)       { std::cout << "1. Point&\n"; }
void foo(const Point& pt) { std::cout << "2. const Point&\n"; }
void foo(Point&& pt)      { std::cout << "3. Point&&\n"; }

int main()
{
	Point pt(1, 1);

	// reference 규칙
	foo(pt);  // 인자로 lvalue 전달. 
			  // 1 번 호출
			  // 1 번이 없으면 2번 호출

	foo(Point{1,1} );	// rvalue 전달
						// 3 번 호출
						// 3 번이 없으면 2번 호출

}
// lvalue, rvalue 를 하나의 함수에서 모두 받고 싶다
// => const T& 로!!

// lvalue, rvalue 전용 함수를 따로 만들고 싶다. - C++11 부터 가능
// => T&, T&& 버전을 따로 만드세요






