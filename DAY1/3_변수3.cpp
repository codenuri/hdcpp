#include <iostream>

struct Point
{
	int x, y;
};
void foo(int n)    {} // int n = {3}

void goo(Point pt) {}

int main()
{
	Point p = { 1,2 };

	foo(3);
	foo( { 3 } ); // ok.. C++11 부터는 이코드도 가능합니다.

	goo(p);	
	goo( { 1,2 } ); // ok. C++11 부터 가능한 표기법
}





