
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 
/*
// 아래 부분을 참고해서 "A" 부분을 보세요
void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
// "A"



//-------------------
Point pt(1, 2);

Point foo() // return by value : 복사본을 생성(임시객체)해서 반환
{
	return pt; // return Point{pt} 의 이미
				// 즉, pt를 복사한 임시객체 반환
				// 리턴 임시객체의 수명은 함수호출 문장의 끝(;)
}
Point& goo() // return by reference : 복사본을 생성하지 말라
{
	return pt; 
}
int main()
{
	foo().x = 10; // error. temporary.x = 10 의 코드
	goo().x = 10; // ok. pt.x = 10
}
// 주의사항 : 지역변수를 절대 참조 반환 하지 마세요
Point& goo()
{
	Point p{1,2};
	return p;
}




