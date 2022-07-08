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

// 또 다른 관점
Point f3()
{
	Point p(1, 2);	// p는 전역이 아닌 "지역변수"입니다.
					// 지역변수 p의 수명을 생각해 보세요
	return p;	// p자체는 파괴되지만 반환할 객체가 있어야 합니다.
				// p가 파괴되기 전에 리턴용 임시객체를 만들고
				// p를 파괴후, 임시객체 반환
}

// 주의 할점.. 절대 지역변수는 참조 반환하지 마세요
//		     파괴되지 않은 객체만 참조 반환 가능합니다.
Point& f4()
{
	Point p(1, 2);
	return p;// 버그!!! 컴파일에러는 없지만 경고등이 발생.. 
}





