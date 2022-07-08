#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//=======================================
/*
void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//========================================





Point pt(1, 2);

Point foo()		// return by value : 
{
	return pt;  // pt 자체가 반환되는것이 아닙니다.
}				// pt를 복사한 복사본(임시객체)가 반환됩니다.

Point& goo()    // return by reference
{
	return pt;	// pt 자체(별명)이 반환 됩니다.
}

int main()
{
//	foo(); // 이 위치에는 pt를 복사한 "리턴용도의 임시객체"가 오게 됩니다.
//	foo().x = 10; // error. 임시객체는 등호에 왼쪽에 놓일수 없습니다.
	
	goo().x = 10; // ok.. pt.x = 10 의 의미 입니다.
}





